#include "../include/jmp0_inst.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

bool jmp0_inst::execute(std::string instruction, int & PC, sync_memory <int> * dataMem, int inst_number)
{
    string arg1, out;
    string * parsedA;
    parsedA = split(instruction, ',');
    arg1 = parsedA[0];
    out = parsedA[1];

    int mem1 = 0, mem2 = 0;

    int val1;
    if(arg1.find("$") != string::npos)
    {
        try
        {
            val1 = stoi(arg1.substr(1));
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in jmp0 instruction"));
        } 
        mem1 = 1;
        
    }
    else
    {
        try
        {
            val1 = stoi(arg1);
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in jmp0 instruction"));
        } 
    }

    int go_to_pc;
    if(out.find("$") != string::npos)
    {
        try
        {
            go_to_pc = stoi(out.substr(1));
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in jmp0 instruction"));
        } 
        mem2 = 1;
    }
    else
    {
        try
        {
            go_to_pc = stoi(out);
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in jmp0 instruction"));
        } 
    }

    int index1, index2;

    dataMem->acquire_deadlock_protector();
    if(mem1)
    {
        val1 = dataMem->get(val1);
    }

    if(mem2)
    {
        go_to_pc = dataMem->get(go_to_pc); 
    }
    dataMem->release_deadlock_protector();

    if(go_to_pc > inst_number || go_to_pc < 0)
    {
        throw(std::runtime_error("Instruction memory address out of range"));
    }
    if(val1 == 0)
    {
        PC = go_to_pc-1;
    }



    delete [] parsedA;
    return 0;
}
