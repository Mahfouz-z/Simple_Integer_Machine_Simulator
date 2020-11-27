#include "memory.h"
#include <semaphore.h>

#ifndef SYNC_MEMORY
#define SYNC_MEMORY

template <typename memDataType>
class sync_memory: public memory <memDataType>
{
    private:
        sem_t wrt_lock;
        sem_t readers_shared_lock;
        int read_count;
    public:
        sync_memory(int s=1024);
        bool set(int index, memDataType data);
        memDataType get(int index);
};

#endif