#ifndef MEMORY
#define MEMORY

template <typename memDataType>

class memory
{
    protected:
        memDataType * mem_arr;
        int size;
    public:
        memory(int s = 1024);
        memory(const memory&);
        memory(memory&&);
        ~memory();
        bool set(int index, memDataType data);
        memDataType get(int index);
};

#endif