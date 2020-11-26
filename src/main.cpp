#define DEBUG

#include <iostream>
#include "../include/SIM_Simulator_Driver.h"



using namespace std;

string program_path = "program.txt";
string data_mem_path = "mem_values.txt";
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "Invalid input, please add at least the Instruction Memory path\n";
        return 0; 
    }
    SIM_Simulator_Driver D1;
    program_path = argv[1];
    try
    {
        D1.load_program(program_path);
        if(argc > 2)
        {
            D1.load_data_mem(argv[2]);
        }
        D1.execute_program();
        D1.print_data_mem();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}