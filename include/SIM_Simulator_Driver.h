#ifndef SIM_Sim_DRV
#define SIM_Sim_DRV

#include <iostream>
#include <vector>
#include <mutex>
#include "memory.h"
#include "sync_memory.h"
#include "helper_functions.h"
#include "jmp_inst.h"
#include "jmp0_inst.h"
#include "add_inst.h"
#include "mul_inst.h"
#include "le_inst.h"
#include "neg_inst.h"
#include "ass_inst.h"
#include "write_inst.h"
#include "read_inst.h"

class SIM_Simulator_Driver 
{

    std::vector <memory <std::string>> inst_mem_vec;
    sync_memory <int> data_mem;
    std::vector <int> inst_count_vec;
    int load_program(std::string path, memory <std::string> & core_mem, int & inst_count);
    static void execution_thread(memory <std::string> & core_mem, int & inst_count, sync_memory <int> & data_mem, int ID);
    static std::mutex std_stream_lock;

  public:
    SIM_Simulator_Driver();
    ~SIM_Simulator_Driver();
    int add_core(std::string instr_mem_path);
    int load_data_mem(std::string path);
    int execute_program();
    void print_data_mem(int start = 0, int end = 30);
};

#endif