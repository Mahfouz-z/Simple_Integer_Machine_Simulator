#include "memory.h"
#include <mutex>

#ifndef SYNC_MEMORY
#define SYNC_MEMORY

template <typename memDataType>
class sync_memory: public memory <memDataType>
{
    private:
        std::mutex deadlock_protector;
    public:
        sync_memory(int s = 1024);
        sync_memory(const sync_memory&);
        sync_memory(sync_memory&&);
        ~sync_memory();
        bool set(int index, memDataType data);
        memDataType get(int index);
        void acquire_deadlock_protector();
        void release_deadlock_protector();
};

#endif