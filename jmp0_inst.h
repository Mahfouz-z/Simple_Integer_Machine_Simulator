#ifndef JMP0_INST
#define JMP0_INST
#include "instClass.h"

class jmp0_inst : public instClass
{
    public:
        bool execute(std::string instruction, int & PC, memory <int> * dataMem, int inst_number);
};
#endif