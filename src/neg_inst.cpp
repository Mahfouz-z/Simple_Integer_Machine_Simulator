#include "../include/neg_inst.h"
#include <stdexcept>
#include <string>

using namespace std;

bool neg_inst::execute(std::string instruction, int & PC, sync_memory <int> * dataMem)
{
    string arg1, out;
    string * parsedA;
    parsedA = split(instruction, ',');
    arg1 = parsedA[0];
    out = parsedA[1];

    int val1;
    int mem1 = 0;
    int index1;
    if(arg1.find("$") != string::npos)
    {
        try
        {
            val1 = stoi(arg1.substr(1));
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in neg instruction"));
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
            throw(std::runtime_error("Invalid Argument in neg instruction"));
        } 
    }

    
    if(out.find("$") == string::npos)
    {
        throw(std::runtime_error("Invalid Argument in neg instruction"));
    }
    int write_mem_index;
    try
    {
        write_mem_index = stoi(out.substr(1));
    }
    catch(const std::exception& e)
    {
        throw(std::runtime_error("Invalid Argument in neg instruction"));
    }

    dataMem->acquire_deadlock_protector();
    if (mem1 == 1)
    {
        val1 = dataMem->get(val1);
    }
    dataMem->set(write_mem_index, -1 * val1);
    dataMem->release_deadlock_protector();

    delete [] parsedA;
    return 0;
}
