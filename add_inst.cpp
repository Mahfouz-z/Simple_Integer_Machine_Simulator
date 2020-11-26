#include "add_inst.h"
#include <stdexcept>
#include <string>
#include <iostream>



using namespace std;

bool add_inst::execute(std::string instruction, int & PC, memory <int> * dataMem)
{
    string arg1, arg2, out;
    string * parsedA, * parsedB;
    parsedA = split(instruction, ",");
    arg1 = parsedA[0];
    parsedB = split(parsedA[1], ",");
    arg2 = parsedB[0]; 
    out = parsedB[1];

    int val1, val2;
    if(arg1.find("$") != string::npos)
    {
        try
        {
            val1 = stoi(arg1.substr(1));
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in add instruction, in1"));
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
            throw(std::runtime_error("Invalid Argument in add instruction, in1"));
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
            throw(std::runtime_error("Invalid Argument in add instruction, in2"));
        } 
        val2 = dataMem->get(val2);
    }
    else
    {
        try
        {
            val2 = stoi(arg2);
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in add instruction, in2"));
        } 
    }
    
    if(out.find("$") == string::npos)
    {
        throw(std::runtime_error("Invalid Argument in add instruction, out"));
    }

    int write_mem_index;
    try
    {
        write_mem_index = stoi(out.substr(1));
    }
    catch(const std::exception& e)
    {
        throw(std::runtime_error("Invalid Argument in add instruction, out"));
    }
    
    dataMem->set(write_mem_index, val1 + val2);

    delete [] parsedA;
    delete [] parsedB;
    return 0;
}
