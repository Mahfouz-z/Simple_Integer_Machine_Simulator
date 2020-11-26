#ifndef LE_INST
#define LE_INST
#include "instClass.h"

class le_inst : public instClass
{
    public:
        bool execute(std::string instruction, int & PC, memory <int> * dataMem);
};
#endif