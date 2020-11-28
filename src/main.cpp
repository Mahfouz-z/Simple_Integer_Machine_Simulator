#include <iostream>
#include "../include/SIM_Simulator_Driver.h"



using namespace std;


int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        cout << "Invalid input, please add data_mem path and at least one instruction memory path\n";
        return 0; 
    }
    SIM_Simulator_Driver D1;
    try
    {
        D1.load_data_mem(argv[1]);
        for (int i = 2; i < argc; i++)
        {
            D1.add_core(argv[i]);
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