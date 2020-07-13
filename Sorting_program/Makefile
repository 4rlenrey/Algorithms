CC = g++
FLAGS = -Wall

OBJ =\
	main.o\
	random_values.o\
	testing_algorithm.o\
	writing_out.o\
	S0rting_algorithms/selection_sort.o\
	S0rting_algorithms/bubble_sort.o

all: main

clean:
	@echo Deleting files
	@rm -f *.o S0rting_algorithms/*.o

.c.o:
	$(CC)  -c $(INCLUDES) $(FLAGS) $<

main: $(OBJ)
	$(CC)  $(OBJ) -o program
