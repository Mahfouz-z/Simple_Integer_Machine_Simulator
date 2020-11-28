#ifndef READ_INST
#define READ_INST
#include "instClass.h"
#include <mutex>

class read_inst : public instClass
{
        static std::mutex std_in_lock;
    public:
        bool execute(std::string instruction, int & PC, sync_memory <int> * dataMem, std::mutex & std_stream_lock);
};
#endif