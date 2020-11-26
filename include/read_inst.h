#ifndef READ_INST
#define READ_INST
#include "instClass.h"

class read_inst : public instClass
{
    public:
        bool execute(std::string instruction, int & PC, memory <int> * dataMem);
};
#endif