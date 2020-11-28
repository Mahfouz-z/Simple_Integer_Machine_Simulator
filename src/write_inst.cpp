#include "../include/write_inst.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;



bool write_inst::execute(std::string instruction, int & PC, sync_memory <int> * dataMem, mutex & std_stream_lock)
{
    int index;
    bool flag = 1;

    if(instruction.find("$") == string::npos)
    {
        
        flag = 0;
        //cout << "here!";
    }

    if(flag)
    {
        try
        {
            index = stoi(instruction.substr(1));
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in write instruction"));
        }
        dataMem->acquire_deadlock_protector();
        int val = dataMem -> get(index);
        std_stream_lock.lock();
        dataMem->release_deadlock_protector();
        cout << "Data Mem Value at index " << index << " is " << val << endl;
        
        std_stream_lock.unlock();
    }
    else
    {
        std_stream_lock.lock();
        cout << instruction << endl;
        std_stream_lock.unlock();           
    }
    return 0;
}
