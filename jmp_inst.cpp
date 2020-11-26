#include "jmp_inst.h"
#include <stdexcept>
#include <string>

using namespace std;

bool jmp_inst::execute(std::string instruction, int & PC, memory <int> * dataMem)
{
    int go_to_pc;
    if(instruction.find("$") != string::npos)
    {
        try
        {
            go_to_pc = stoi(instruction.substr(1));
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in jmp instruction"));
        } 
        go_to_pc = dataMem->get(go_to_pc);
    }
    else
    {
        try
        {
            go_to_pc = stoi(instruction);
        }
        catch(const std::exception& e)
        {
            throw(std::runtime_error("Invalid Argument in jmp instruction"));
        } 
    }
    
    PC = go_to_pc-1;
    return 0;
}
