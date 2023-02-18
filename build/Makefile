OBJS := *.o
SRCS := source/*.cpp
HEADERS := util/*.h

output: $(OBJS)
	g++ $(OBJS) -o output

$(OBJS): $(SRCS) $(HEADERS) 
	g++ -c $(SRCS)

clean:
	rm *.o output