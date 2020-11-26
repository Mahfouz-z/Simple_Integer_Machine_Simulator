#ifndef SIM_Sim_DRV
#define SIM_Sim_DRV

#include <iostream>
#include "memory.h"
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
    memory  <std::string> inst_mem;
    memory <int> data_mem;
    int inst_number;

  public:
    SIM_Simulator_Driver();
    ~SIM_Simulator_Driver();
    int load_program(std::string path);
    int load_data_mem(std::string path);
    int execute_program();
    void print_data_mem(int start = 0, int end = 30);
};

#endif