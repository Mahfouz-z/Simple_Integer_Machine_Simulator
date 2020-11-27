#include <iostream>
#include "../include/sync_memory.h"
#include <stdexcept>


using namespace std;


template <typename memDataType>
sync_memory<memDataType>::sync_memory(int s)
{
    sem_init(&wrt_lock, 0, 1);
    sem_init(&readers_shared_lock, 0, 1);
    read_count = 0;
}


template <typename memDataType>
bool sync_memory<memDataType>::set(int index, memDataType data)
{
    sem_wait(&wrt_lock);
    if(index >= 0 && index < this->size)
    {
        this->mem_arr[index] = data; 
    }   
    else
    {
        sem_post(&wrt_lock);
        throw(invalid_argument("Invalid Memorey Address"));
        return 1;
    }
    sem_post(&wrt_lock);
    return 0;
}



template <typename memDataType>
memDataType sync_memory<memDataType>::get(int index)
{
    //cout << "reading\n";
    sem_wait(&readers_shared_lock);
        read_count++;
        if(read_count == 1)
        {
            sem_wait(&wrt_lock);
        }
    sem_post(&readers_shared_lock);

    if(index >= 0 && index < this->size)
    {
        return this->mem_arr[index];
    }   
    else
    {
        throw(invalid_argument("Invalid Memorey Address"));
    }

    sem_wait(&readers_shared_lock);
        read_count--;
        if(read_count == 0)
        {
            sem_post(&wrt_lock);
        }
    sem_post(&readers_shared_lock);

}

template class sync_memory<int>;