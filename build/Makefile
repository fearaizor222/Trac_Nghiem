SHELL := pwsh.exe
.SHELLFLAGS := -NoProfile -Command

CXX := g++
CXXFLAGS := -Wall -std=c++11

OBJS := *.o
SRCS := ../source/*.cpp
HEADERS := ../header/*.h

output: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o output.exe

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(SRCS)

run:
	start cmd "/c ; output &pause\"

clean:
	rm *.o , output.exe