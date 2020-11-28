To Compile run: <br/>
    make all <br/>

To run: <br/>
    ./main <data_mem_path> <program_0_path> <program_1_path> ......  <br/>
    - You have to provide data_mem_path and at least one program path. <br/>

To run my test: <br/>
    Repeat the program.txt part as much cores as you need <br/>
    ./bin/main mem_values.txt program.txt program.txt program.txt program.txt program.txt <br/>   

To write a data_mem file as the included data_mem file or REPEAT: <br/>
    - <memory address index> , <memory address value> <br/>
     

Test Program Explanation: <br/>
    - Each Thread Adds a 2 to memorey address $1 <br/>
    - Each Thread Multiplies the value at memory address $2 by 2 <br/>
    - Each thread negates the address at memory address $3 <br/>

Instructions for programs: <br/>
    - The parser is sensitive to newlines, don't add lines with no instructions <br/>
    - Don't leave a space before instructions <br/>
    - use $ before data memory addresses (deal with it as RISC-V registers) <br/>
    - Since no opcodes for instructions, Instruction memory shouldn't be accessible by and Integer only machine <br/>