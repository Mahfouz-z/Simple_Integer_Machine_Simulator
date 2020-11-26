#include "write_inst.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

bool write_inst::execute(std::string instruction, int & PC, memory <int> * dataMem)
{
    int index;

    if(instruction.find("$") == string::npos)
    {
        throw(std::runtime_error("Invalid Argument in write instruction"));
    }
    try
    {
        index = stoi(instruction.substr(1));
    }
    catch(const std::exception& e)
    {
        throw(std::runtime_error("Invalid Argument in write instruction"));
    }

    int val = dataMem -> get(index);
    cout << "Instruction Value at index " << index << " is " << val << endl;

    return 0;
}
