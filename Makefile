CC=mpicc
BIN=bin/
SRC=src/
INCLUDES=include/
EXEC=k_means
CFLAGS=-Wall -O2
.DEFAULT_GOAL=k_means	

k_means:$(SRC)k_means.c $(BIN)utils.o
		$(CC) $(CFLAGS) $(SRC)k_means.c $(BIN)utils.o -o $(BIN)$(EXEC) -lm
		
$(BIN)utils.o: $(SRC)utils.c $(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(SRC)utils.c -o $(BIN)utils.o

clean:
		rm -r bin/*
run:
		mpirun -np 2 ./$(BIN)$(EXEC) 10000000 4
