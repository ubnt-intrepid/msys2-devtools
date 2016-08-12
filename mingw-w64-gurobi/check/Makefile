SRCS			:= $(wildcard *.cpp)
OBJS			:= $(SRCS:.cpp=.o)
TARGETS		:= example

CXXFLAGS	:= -std=c++14 -march=x86-64 -Wall -Wextra -O2
LIB				:= -lgurobi_c++ -lgurobi65

all: $(TARGETS) 

$(TARGETS): $(OBJS)
	g++ -o $@ $(OBJS) $(INCDIR) $(LIBDIR) $(LIB)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<


.PHONY:run
run: $(TARGETS)
	./$(TARGETS)


.PHONY:clean
clean:
	$(RM) $(TARGETS) $(OBJS)
