#include "../include/ass_inst.h"
#include <stdexcept>
#include <string>

using namespace std;

bool ass_inst::execute(std::string instruction, int & PC, memory <int> * dataMem)
{
    string arg1, out;
    string * parsedA;
    parsedA = split(instruction, ",");
    arg1 = parsedA[0];
    out = parsedA[1];

    int val1;
    if(arg1.find("$") != string::npos)
    {
        try
        {
            val1 = stoi(arg1.substr(1));
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in ass instruction"));
        } 
        val1 = dataMem->get(val1);
    }
    else
    {
        try
        {
            val1 = stoi(arg1);
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in ass instruction"));
        } 
    }

    
    if(out.find("$") == string::npos)
    {
        throw(std::runtime_error("Invalid Argument in ass instruction"));
    }
    int write_mem_index;
    try
    {
        write_mem_index = stoi(out.substr(1));
    }
    catch(const std::exception& e)
    {
        throw(std::runtime_error("Invalid Argument in ass instruction"));
    }
    
    dataMem->set(write_mem_index, val1);

    delete [] parsedA;
    return 0;
}
