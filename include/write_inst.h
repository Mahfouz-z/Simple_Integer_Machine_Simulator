#ifndef WRITE_INST
#define WRITE_INST
#include "instClass.h"
#include <mutex>

class write_inst : public instClass
{   
        
    public:
        bool execute(std::string instruction, int & PC, sync_memory <int> * dataMem, std::mutex & std_stream_lock);
};
#endif