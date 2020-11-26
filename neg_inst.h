#ifndef NEG_INST
#define NEG_INST
#include "instClass.h"

class neg_inst : public instClass
{
    public:
        bool execute(std::string instruction, int & PC, memory <int> * dataMem);
};
#endif