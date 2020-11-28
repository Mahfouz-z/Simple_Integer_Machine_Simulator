#ifndef INST
#define INST
#include <string>
#include "memory.h"
#include "sync_memory.h"
#include "helper_functions.h"

class instClass
{
    public:
        virtual bool execute(std::string instruction, int & PC, sync_memory <int> * dataMem){}
};
#endif