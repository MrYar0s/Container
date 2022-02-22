PROG = vec
OBJ = vector.o test_sort2.o
CCFLAGS = -g -Wall

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^

clean:
	-rm *.o

depend:
	$(CC) -MM $(CCFLAGS) *.cc $(OBJ:.o = .c) > .depend
-include .depend