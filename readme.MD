To Compile run:
    make all

To run:
    ./main <program_path> <data_mem_path>

To run my test:
    ./main program.txt mem_values.txt

Test Program Explanation: <br/>
    - get a value from the user using READ and write it to mem_data[1] <br/>
    - REPEAT(10)  --> done using a combination of ADD, LE, and JMP0 <br/>
        &nbsp;&nbsp;&nbsp;- mem_data[1] = mem_data[1] + mem_data[1] <br/>
        &nbsp;&nbsp;&nbsp;- mem_data[1] = mem_data[1] * 2 <br/>
        &nbsp;&nbsp;&nbsp;- mem_data[1] = -mem_data[1] <br/>
        &nbsp;&nbsp;&nbsp;- Write(mem_data[1]) <br/>
    - Assign mem_data[14] = mem_data[1] <br/>
    - JMP the next; thus,  "mem_data[13] = mem_data[1]" is not executed <br/>
    - HALT is found and program is terminated; thus, "mem_data[15] = mem_data[1]" is not executed <br/>

Instructions for programs: <br/>
    &nbsp;&nbsp;&nbsp;- The parser is sensitive to newlines, don't add lines with no instructions <br/>
    &nbsp;&nbsp;&nbsp;- Don't leave a space before instructions <br/>
    &nbsp;&nbsp;&nbsp;- use $ before data memory addresses (deal with it as RISC-V registers) <br/>
