#include <iostream>
#include "../include/sync_memory.h"
#include <stdexcept>


using namespace std;

template <typename memDataType>
sync_memory<memDataType>::sync_memory(int s)
{
   
}

template <typename memDataType>
sync_memory<memDataType>::sync_memory (const sync_memory& a) //copy
{ 
    // for(int i=0; i<a.size; i++)
    // {
    //     this->index_lock_table[i]=a.index_lock_table[i];
    // }
}

template <typename memDataType>
sync_memory<memDataType>::sync_memory (sync_memory&& a) //move
{ 
    
}

template <typename memDataType>
sync_memory<memDataType>::~sync_memory()
{
    
}


template <typename memDataType>
void sync_memory<memDataType>::acquire_deadlock_protector()
{
    deadlock_protector.lock();
}

template <typename memDataType>
void sync_memory<memDataType>::release_deadlock_protector()
{
    deadlock_protector.unlock();
}





template <typename memDataType>
bool sync_memory<memDataType>::set(int index, memDataType data)
{
    if(index >= 0 && index < this->size)
    {
        this->mem_arr[index] = data; 
    }   
    else
    {
        throw(invalid_argument("Invalid Memory Address in sync_memory setter"));
        return 1;
    }
    return 0;
}



template <typename memDataType>
memDataType sync_memory<memDataType>::get(int index)
{
    if(index >= 0 && index < this->size)
    {
        return this->mem_arr[index];
    }   
    else
    {
        throw(invalid_argument("Invalid Memory Address in sync_memory getter"));
    }
}

template class sync_memory<int>;