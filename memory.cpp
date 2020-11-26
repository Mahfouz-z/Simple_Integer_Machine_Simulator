#include <iostream>
#include "memory.h"
#include <stdexcept>

using namespace std;




template <typename memDataType>
memory<memDataType>::memory(int s):size(s)
{
    if(size > 0)
    {
        mem_arr = new memDataType[size];
    }
    else
    {
        mem_arr = nullptr;
        throw(invalid_argument("Invalid Memorey Size"));
    }
}

template <typename memDataType>
memory<memDataType>::memory (const memory& a):size(a.size), mem_arr(new memDataType[a.size]) //copy
{ 
    for(int i=0; i<size; i++)
        this->mem_arr[i]=a.mem_arr[i];
}

template <typename memDataType>
memory<memDataType>::memory (memory&& a):size(a.size), mem_arr(a.mem_arr) //move
{ 
    a.mem_arr = nullptr;
    a.size = 0;
}

template <typename memDataType>
memory<memDataType>::~memory()
{
    if(mem_arr!=nullptr)
    {
        delete [] mem_arr;
        mem_arr = nullptr;
    }
}

template <typename memDataType>
bool memory<memDataType>::set(int index, memDataType data)
{
    if(index >= 0 && index < this->size)
    {
        this->mem_arr[index] = data; 
        return 0;
    }   
    else
    {
        throw(invalid_argument("Invalid Memorey Address"));
        return 1;
    }
    
}



template <typename memDataType>
memDataType memory<memDataType>::get(int index)
{
    if(index >= 0 && index < this->size)
    {
        return this->mem_arr[index];
    }   
    else
    {
        throw(invalid_argument("Invalid Memorey Address"));
    }
}


template class memory<int>;
template class memory<string>;