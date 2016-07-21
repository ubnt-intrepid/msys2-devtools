TARGET	:= ../libgurobi_c++.a
SRCS		:= $(wildcard *.cpp)
OBJS		:= $(SRCS:.cpp=.o)
INCDIR	:= -I ..

all: $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(AR) r $(TARGET) $(OBJS)

.cpp.o: 
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCDIR) $(LIBDIR) $(LIB)

.PHONY: clean
clean:
	$(RM) $(TARGETS) $(OBJS)

