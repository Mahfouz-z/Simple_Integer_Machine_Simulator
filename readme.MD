To Compile run:
    make all

To run:
    ./main <program_path> <data_mem_path>

To run my test:
    ./main program.txt mem_values.txt

Test Program Explanation:
    - get a value from the user using READ and write it to mem_data[1]
    - REPEAT(10)  --> done using a combination of ADD, LE, and JMP0
        - mem_data[1] = mem_data[1] + mem_data[1]
        - mem_data[1] = mem_data[1] * 2
        - mem_data[1] = -mem_data[1]
        - Write(mem_data[1])
    - Assign mem_data[14] = mem_data[1]
    - JMP the next; thus,  "mem_data[13] = mem_data[1]" is not executed
    - HALT is found and program is terminated; thus, "mem_data[15] = mem_data[1]" is not executed

Instructions for programs:
    - The parser is sensitive to newlines, don't add lines with no instructions
    - Don't leave a space before instructions 
    - use $ before data memory addresses (deal with it as RISC-V registers)
