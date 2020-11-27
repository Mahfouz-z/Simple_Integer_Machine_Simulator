#include "../include/write_inst.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;



bool write_inst::execute(std::string instruction, int & PC, memory <int> * dataMem, mutex & std_stream_lock)
{
    int index;
    bool flag = 1;

    if(instruction.find("$") == string::npos)
    {
        
        flag = 0;
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

        int val = dataMem -> get(index);
        std_stream_lock.lock();
        cout << "Instruction Value at index " << index << " is " << val << endl;
        std_stream_lock.unlock();
    }
    std_stream_lock.lock();
    cout << instruction << endl;
    std_stream_lock.unlock();

    return 0;
}
