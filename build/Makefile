SHELL := pwsh.exe
.SHELLFLAGS := -NoProfile -Command

CXX := g++
CXXFLAGS := -Wall -std=c++11
LINKER := -I ../header/ -L ../source/ -lraylib -lopengl32 -lgdi32 -lwinmm

OBJS := *.o
SRCS := ../source/*.cpp
HEADERS := ../header/*.h

output: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o output.exe $(LINKER) $(UI)

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(SRCS)

run:
	start cmd "/c ; output & pause"

clean:
	rm *.o , output.exe