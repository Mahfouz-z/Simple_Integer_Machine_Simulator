#ifndef INST
#define INST
#include <string>
#include "memory.h"
#include "helper_functions.h"

class instClass
{
    public:
        virtual bool execute(std::string instruction, int & PC, memory <int> * dataMem){}
};
#endif