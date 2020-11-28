#ifndef JMP_INST
#define JMP_INST
#include "instClass.h"

class jmp_inst : public instClass
{
    public:
        bool execute(std::string instruction, int & PC, sync_memory <int> * dataMem);
};
#endif