#ifndef ASS_INST
#define ASS_INST
#include "instClass.h"

class ass_inst : public instClass
{
    public:
        bool execute(std::string instruction, int & PC, memory <int> * dataMem);
};
#endif