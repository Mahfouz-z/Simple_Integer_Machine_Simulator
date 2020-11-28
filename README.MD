To Compile run:
    make all

To run:
    ./main <data_mem_path> <program_0_path> <program_1_path> ...... 
    - You have to provide data_mem_path and at least one program path.

To run my test:
    Repeat the program.txt part as much cores as you need
    ./bin/main mem_values.txt program.txt program.txt program.txt program.txt program.txt   

To write a data_mem file as the included data_mem file or REPEAT:
    - <memory address index> , <memory address value>
     

Test Program Explanation: <br/>
    - Each Thread Adds a 2 to memorey address $1
    - Each Thread Multiplies the value at memory address $2 by 2
    - Each thread negates the address at memory address $3

Instructions for programs: <br/>
    - The parser is sensitive to newlines, don't add lines with no instructions <br/>
    - Don't leave a space before instructions <br/>
    - use $ before data memory addresses (deal with it as RISC-V registers) <br/>
