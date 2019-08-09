.PHONY: test clean
 
LIB_DIR=../lib
SRC_DIR=../src
CPP_FLAGS=-std=c++11 -Wall
 
INCLUDES=\
	-I$(LIB_DIR)/catch \
	-I${SRC_DIR}

SRCS=test.cpp \
	${SRC_DIR}/SignalProcessing.cpp
 
OBJS=$(SRCS:.cpp=.o)

TEST_SRC=TestSignalProcessing.cpp
 
test: $(OBJS)
	@g++ $(CPP_FLAGS) $(INCLUDES) -o run_test $(OBJS) $(TEST_SRC)
	@./run_test
 
%.o : %.cpp
	g++ $(CPP_FLAGS) $(INCLUDES) -c $< -o $@
 
clean:
	rm $(OBJS)