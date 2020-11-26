#include "../include/SIM_Simulator_Driver.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <iomanip>
//#define DEBUG

using namespace std;


SIM_Simulator_Driver::SIM_Simulator_Driver():inst_mem(memory <std::string> (1024)), data_mem(memory <int> (1024)), inst_number(0)
{
    
}

SIM_Simulator_Driver::~SIM_Simulator_Driver()
{

}


int SIM_Simulator_Driver::load_program(string path)
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
        inst_mem.set(i, line);
        #ifdef DEBUG
            cout << inst_mem.get(i) << endl;
        #endif
        i++;
    }
    inst_number = i;
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
            parsed = split(line, ",");
            index = stoi(parsed[0]);
            val = stoi(parsed[1]);
            data_mem.set(index, val);
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("specified data memorey is invalid"));
        }
    }
    return 0;
}




int SIM_Simulator_Driver::execute_program()
{
    for (int pc = 0; pc < inst_number; pc++)
    {
        string current_inst, inst_type, operands;
        string * parsed;
        current_inst = inst_mem.get(pc);
        parsed = split(current_inst, " ");
        inst_type = removeSpaces(parsed[0]);
        operands = removeSpaces(parsed[1]);
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
            if(pc > inst_number || pc < -1)
            {
                throw(std::runtime_error("Instruction memorey address out of range"));
            }
        }
        else if(inst_type == "JMP0")
        {
            jmp0_inst().execute(operands, pc, &data_mem, inst_number);        
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
            read_inst().execute(operands, pc, &data_mem);
        }
        else if(inst_type == "WRITE")
        {
            write_inst().execute(operands, pc, &data_mem);
        }
        else if(inst_type == "HALT")
        {
            cout << "HALT FOUND, APP RUNNING IS DONE" << endl;
            break;
        }
        else
        {
            throw(std::runtime_error("Unsupported Instruction"));
        }
    }
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