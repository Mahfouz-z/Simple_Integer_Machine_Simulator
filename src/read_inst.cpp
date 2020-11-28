#include "../include/read_inst.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

bool read_inst::execute(std::string instruction, int & PC, sync_memory <int> * dataMem, mutex & std_stream_lock)
{
    int index;

    if(instruction.find("$") == string::npos)
    {
        throw(std::runtime_error("Invalid Argument in read instruction"));
    }
    try
    {
        index = stoi(instruction.substr(1));
    }
    catch(const std::exception& e)
    {
        throw(std::runtime_error("Invalid Argument in read instruction"));
    }

    string read_val;
    int val;

    dataMem->acquire_deadlock_protector();
    std_stream_lock.lock();
    cout << "ُEnter an integer value to be written to the specified memorey address\n";
    cin >> read_val;
    try
    {
        val = stoi(read_val);
    }
    catch(const std::exception& e)
    {
        std_stream_lock.unlock();
        throw(std::runtime_error("Value cannot be interperted as int"));
    }  
    
    dataMem -> set(index, val);
    dataMem->release_deadlock_protector();
    std_stream_lock.unlock();
    return 0;
}
