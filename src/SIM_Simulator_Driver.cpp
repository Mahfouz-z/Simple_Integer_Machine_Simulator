#include "../include/SIM_Simulator_Driver.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <iomanip>
#include <thread>
//#define DEBUG

using namespace std;

mutex SIM_Simulator_Driver::std_stream_lock;

SIM_Simulator_Driver::SIM_Simulator_Driver():data_mem(sync_memory <int> (1000))
{

}

SIM_Simulator_Driver::~SIM_Simulator_Driver()
{

}

int SIM_Simulator_Driver::add_core(std::string instr_mem_path)
{
    memory <std::string> core_mem;
    int inst_count;
    int ret_val = SIM_Simulator_Driver::load_program(instr_mem_path, core_mem, inst_count);
    if(core_mem.get(inst_count-1).find("HALT") == string::npos)
    {
        throw(runtime_error("Invalid Program, no HALT instruction used at the end of the program"));
    }

    inst_mem_vec.push_back(core_mem);
    inst_count_vec.push_back(inst_count);
    return ret_val;
}

int SIM_Simulator_Driver::load_program(string path, memory <std::string> & core_mem, int & inst_count)
{
    ifstream infile(path);
    if(!infile)
    {
        throw(std::invalid_argument("couldn't open the specified file path"));
    }

    string line; 
    int i = 0;
    while (getline(infile, line)) 
    {
        line = removeEndls(line);
        core_mem.set(i, line);
        #ifdef DEBUG
            cout << core_mem.get(i) << endl;
        #endif
        i++;
    }
    inst_count = i;
    infile.close();
    return 0;
}

int SIM_Simulator_Driver::load_data_mem(string path)
{
    ifstream infile(path);
    if(!infile)
    {
        throw(std::invalid_argument("couldn't open the specified file path"));
    }

    string line; 
    int index;
    int val;
    while (getline(infile, line)) 
    {
        
        try
        {
            string * parsed;
            line = removeSpaces(line);
            parsed = split(line, ',');
            index = stoi(parsed[0]);
            //cout << parsed[1] << endl;
            val = stoi(parsed[1]);
            data_mem.set(index, val);
        }
        catch(const std::exception& e)
        {
            cout << e.what() << endl;
            throw(std::runtime_error("specified data memorey is invalid"));
        }
    }
    return 0;
}


void SIM_Simulator_Driver::execution_thread(memory <std::string> & core_mem, int & inst_count, sync_memory <int> & data_mem, int ID)
{
    try
    {
         for (int pc = 0; pc < inst_count; pc++)
            {
                string current_inst, inst_type, operands;
                string * parsed;
                current_inst = core_mem.get(pc);
                
                parsed = split(current_inst, ' ');
                
                inst_type = removeSpaces(parsed[0]);
                
                operands = removeSpaces(parsed[1]);
                //cout << inst_type<< " " << operands << endl;
                delete [] parsed;
                
                if(inst_type == "ADD")
                {
                    add_inst().execute(operands, pc, &data_mem);
                }
                else if(inst_type == "NEG")
                {
                    neg_inst().execute(operands, pc, &data_mem);
                }
                else if(inst_type == "MUL")
                {
                    mul_inst().execute(operands, pc, &data_mem);
                }
                else if(inst_type == "JMP")
                {
                    jmp_inst().execute(operands, pc, &data_mem);
                    if(pc > inst_count || pc < -1)
                    {
                        throw(std::runtime_error("Instruction memorey address out of range"));
                    }
                }
                else if(inst_type == "JMP0")
                {
                    jmp0_inst().execute(operands, pc, &data_mem, inst_count);        
                }
                else if(inst_type == "ASS")
                {
                    ass_inst().execute(operands, pc, &data_mem);
                }
                else if(inst_type == "LE")
                {
                    le_inst().execute(operands, pc, &data_mem);
                }
                else if(inst_type == "READ")
                {
                    read_inst().execute(operands, pc, &data_mem, std_stream_lock);
                }
                else if(inst_type == "WRITE")
                {
                    write_inst().execute(operands, pc, &data_mem, std_stream_lock);
                }
                else if(inst_type == "HALT")
                {
                    std_stream_lock.lock();
                    cout << "HALT FOUND, APP RUNNING IS DONE ON CORE: " << ID << endl;
                    std_stream_lock.unlock();
                    break;
                }
                else
                {
                    throw(std::runtime_error("Unsupported Instruction" + inst_type));
                }
            }
    }
    catch(const std::exception& e)
    {
        std_stream_lock.lock();
        std::cerr << "Execution had thrown an exception in core with Index: " << ID << endl;
        std::cerr << "       " << e.what() << '\n';
        std_stream_lock.unlock();
    }
    
}

int SIM_Simulator_Driver::execute_program()
{
    vector <thread> thread_holder;
    try
    {
        for(int i = 0; i < inst_mem_vec.size(); i++)
        {
            thread_holder.push_back(thread(execution_thread, std::ref(inst_mem_vec[i]), std::ref(inst_count_vec[i]), std::ref(data_mem), i));
        }
        for(int i = 0; i < inst_mem_vec.size(); i++)
        {
            thread_holder[i].join();
        }
    }
    catch(const std::exception& e)
    {
        throw;
    }
    return 0;
}


void SIM_Simulator_Driver::print_data_mem(int start, int end)
{
    for(int i = start; i < end; i++)
    {
        cout << setw(10) << data_mem.get(i);
        if(i%6 == 5)
            cout << endl; 
    }
}