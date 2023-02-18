CXX := g++
CXXFLAGS := -Wall -std=c++11

OBJS := *.o
SRCS := ../source/*.cpp
HEADERS := ../header/*.h

output: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o output

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(SRCS)

clean:
	del *.o output.exe