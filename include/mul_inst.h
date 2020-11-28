#ifndef MUL_INST
#define MUL_INST
#include "instClass.h"

class mul_inst : public instClass
{
    public:
        bool execute(std::string instruction, int & PC, sync_memory <int> * dataMem);
};
#endif