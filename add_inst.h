#ifndef ADD_INST
#define ADD_INST
#include "instClass.h"

class add_inst : public instClass
{
    public:
        bool execute(std::string instruction, int & PC, memory <int> * dataMem);
};
#endif