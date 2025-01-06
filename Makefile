OBJ=brain

all: $(OBJ)

brain: main.c list.c neuron.c cluster.c network.c 
	gcc -Wall -Werror -std=c99 $^ -o $@ 

clean:
	rm -f *.o
	rm -f ./$(OBJ)
