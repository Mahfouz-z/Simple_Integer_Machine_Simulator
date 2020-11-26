#ifndef WRITE_INST
#define WRITE_INST
#include "instClass.h"

class write_inst : public instClass
{
    public:
        bool execute(std::string instruction, int & PC, memory <int> * dataMem);
};
#endif