#include "../include/mul_inst.h"
#include <stdexcept>
#include <string>

using namespace std;

bool mul_inst::execute(std::string instruction, int & PC, sync_memory <int> * dataMem)
{
    string arg1, arg2, out;
    string * parsedA, * parsedB;
    parsedA = split(instruction, ',');
    arg1 = parsedA[0];
    parsedB = split(parsedA[1], ',');
    arg2 = parsedB[0];
    out = parsedB[1];

    int val1, val2;
    int mem1 = 0, mem2 = 0;
    int index1, index2;

    if(arg1.find("$") != string::npos)
    {
        try
        {
            val1 = stoi(arg1.substr(1));
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in mul instruction"));
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
            throw(std::runtime_error("Invalid Argument in mul instruction"));
        } 
    }


    if(arg2.find("$") != string::npos)
    {
        try
        {
            val2 = stoi(arg2.substr(1));
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in mul instruction"));
        } 
        mem2 = 1;
    }
    else
    {
        try
        {
            val2 = stoi(arg2);
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in mul instruction"));
        } 
    }
    
    if(out.find("$") == string::npos)
    {
        throw(std::runtime_error("Invalid Argument in mul instruction"));
    }

    int write_mem_index;
    try
    {
        write_mem_index = stoi(out.substr(1));
    }
    catch(const std::exception& e)
    {
        throw(std::runtime_error("Invalid Argument in mul instruction"));
    }

    dataMem->acquire_deadlock_protector();
    if (mem1 == 1)
    {
        val1 = dataMem->get(val1);
    }
    if (mem2 == 1)
    {
        val2 = dataMem->get(val2);
    }
    
    dataMem->set(write_mem_index, val1 * val2);
    dataMem->release_deadlock_protector();

    delete [] parsedA;
    delete [] parsedB;
    return 0;
}
