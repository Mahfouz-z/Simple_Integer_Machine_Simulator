CXX=g++

all: memory.o SIM_Simulator_Driver.o main.o write_inst.o le_inst.o add_inst.o ass_inst.o read_inst.o jmp0_inst.o jmp_inst.o mul_inst.o neg_inst.o helper_functions.o
	$(CXX) -O0 -std=c++11 -ggdb -fno-elide-constructors -o main main.o memory.o SIM_Simulator_Driver.o write_inst.o le_inst.o add_inst.o ass_inst.o read_inst.o jmp0_inst.o jmp_inst.o mul_inst.o neg_inst.o helper_functions.o

main.o: main.cpp
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o main.o main.cpp 


SIM_Simulator_Driver.o: SIM_Simulator_Driver.cpp SIM_Simulator_Driver.h  helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o SIM_Simulator_Driver.o SIM_Simulator_Driver.cpp

memory.o: memory.cpp memory.h 
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o memory.o memory.cpp  


write_inst.o: write_inst.cpp write_inst.h helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o write_inst.o write_inst.cpp

le_inst.o: le_inst.cpp le_inst.h helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o le_inst.o le_inst.cpp

read_inst.o: read_inst.cpp read_inst.h helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o read_inst.o read_inst.cpp

neg_inst.o: neg_inst.cpp neg_inst.h helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o neg_inst.o neg_inst.cpp

mul_inst.o: mul_inst.cpp mul_inst.h helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o mul_inst.o mul_inst.cpp

add_inst.o: add_inst.cpp add_inst.h helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o add_inst.o add_inst.cpp

ass_inst.o: ass_inst.cpp ass_inst.h helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o ass_inst.o ass_inst.cpp

jmp0_inst.o: jmp0_inst.cpp jmp0_inst.h helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o jmp0_inst.o jmp0_inst.cpp

jmp_inst.o: jmp_inst.cpp jmp_inst.h helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o jmp_inst.o jmp_inst.cpp 

helper_functions.o: helper_functions.cpp helper_functions.h
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o helper_functions.o helper_functions.cpp 

clean:
	rm -rf main.o memory.o SIM_Simulator_Driver.o write_inst.o le_inst.o add_inst.o ass_inst.o read_inst.o jmp0_inst.o jmp_inst.o mul_inst.o neg_inst.o helper_functions.o main