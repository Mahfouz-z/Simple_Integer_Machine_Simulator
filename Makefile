CXX=g++
BUILD_DIR=build/
SRC_DIR=src/
BIN_DIR=bin/
SPIKE_DIR=spike/

all: $(BUILD_DIR)memory.o $(BUILD_DIR)sync_memory.o $(BUILD_DIR)SIM_Simulator_Driver.o $(BUILD_DIR)main.o $(BUILD_DIR)write_inst.o $(BUILD_DIR)le_inst.o $(BUILD_DIR)add_inst.o $(BUILD_DIR)ass_inst.o $(BUILD_DIR)read_inst.o $(BUILD_DIR)jmp0_inst.o $(BUILD_DIR)jmp_inst.o $(BUILD_DIR)mul_inst.o $(BUILD_DIR)neg_inst.o $(BUILD_DIR)helper_functions.o
	$(CXX) -O0 -std=c++11 -ggdb -fno-elide-constructors -o $(BIN_DIR)main $(BUILD_DIR)main.o $(BUILD_DIR)memory.o $(BUILD_DIR)sync_memory.o $(BUILD_DIR)SIM_Simulator_Driver.o $(BUILD_DIR)write_inst.o $(BUILD_DIR)le_inst.o $(BUILD_DIR)add_inst.o $(BUILD_DIR)ass_inst.o $(BUILD_DIR)read_inst.o $(BUILD_DIR)jmp0_inst.o $(BUILD_DIR)jmp_inst.o $(BUILD_DIR)mul_inst.o $(BUILD_DIR)neg_inst.o $(BUILD_DIR)helper_functions.o -lrt -pthread

$(BUILD_DIR)main.o: $(SRC_DIR)main.cpp
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)main.o $(SRC_DIR)main.cpp 


$(BUILD_DIR)SIM_Simulator_Driver.o: $(SRC_DIR)SIM_Simulator_Driver.cpp $(BUILD_DIR)helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)SIM_Simulator_Driver.o $(SRC_DIR)SIM_Simulator_Driver.cpp

$(BUILD_DIR)memory.o: $(SRC_DIR)memory.cpp 
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)memory.o $(SRC_DIR)memory.cpp  

$(BUILD_DIR)sync_memory.o: $(SRC_DIR)sync_memory.cpp 
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)sync_memory.o $(SRC_DIR)sync_memory.cpp  

$(BUILD_DIR)write_inst.o: $(SRC_DIR)write_inst.cpp $(BUILD_DIR)helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)write_inst.o $(SRC_DIR)write_inst.cpp

$(BUILD_DIR)le_inst.o: $(SRC_DIR)le_inst.cpp $(BUILD_DIR)helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)le_inst.o $(SRC_DIR)le_inst.cpp

$(BUILD_DIR)read_inst.o: $(SRC_DIR)read_inst.cpp $(BUILD_DIR)helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)read_inst.o $(SRC_DIR)read_inst.cpp

$(BUILD_DIR)neg_inst.o: $(SRC_DIR)neg_inst.cpp $(BUILD_DIR)helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)neg_inst.o $(SRC_DIR)neg_inst.cpp

$(BUILD_DIR)mul_inst.o: $(SRC_DIR)mul_inst.cpp $(BUILD_DIR)helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)mul_inst.o $(SRC_DIR)mul_inst.cpp

$(BUILD_DIR)add_inst.o: $(SRC_DIR)add_inst.cpp $(BUILD_DIR)helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)add_inst.o $(SRC_DIR)add_inst.cpp

$(BUILD_DIR)ass_inst.o: $(SRC_DIR)ass_inst.cpp $(BUILD_DIR)helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)ass_inst.o $(SRC_DIR)ass_inst.cpp

$(BUILD_DIR)jmp0_inst.o: $(SRC_DIR)jmp0_inst.cpp $(BUILD_DIR)helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)jmp0_inst.o $(SRC_DIR)jmp0_inst.cpp

$(BUILD_DIR)jmp_inst.o: $(SRC_DIR)jmp_inst.cpp $(BUILD_DIR)helper_functions.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)jmp_inst.o $(SRC_DIR)jmp_inst.cpp 

$(BUILD_DIR)helper_functions.o: $(SRC_DIR)helper_functions.cpp
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BUILD_DIR)helper_functions.o $(SRC_DIR)helper_functions.cpp 



spike: $(SRC_DIR)spike.cpp
	$(CXX) -std=c++11 -ggdb -O0 -fno-elide-constructors -o $(BIN_DIR)spike $(SRC_DIR)spike.cpp

clean:
	rm -rf build/* bin/*