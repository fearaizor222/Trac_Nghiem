CXX := g++
CXXFLAGS := -Wall -stdc++11

OBJS := *.o
SRCS := ../source/*.cpp
HEADERS := ../header/*.h

output: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o output

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(SRCS)

clean:
	rm *.o output