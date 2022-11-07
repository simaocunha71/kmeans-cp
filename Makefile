CC=gcc
BIN=bin/
SRC=src/
INCLUDES=include/
EXEC=k_means
CFLAGS=-Wall -O2
.DEFAULT_GOAL=k_means	
THREADS = 2 #Change to a desirable number of threads

k_means:$(SRC)k_means.c $(BIN)utils.o
		$(CC) $(CFLAGS) $(SRC)k_means.c $(BIN)utils.o -o $(BIN)$(EXEC) -lm
		
$(BIN)utils.o: $(SRC)utils.c $(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(SRC)utils.c -o $(BIN)utils.o

clean:
		rm -r bin/*
run:
		./$(BIN)$(EXEC)

runseq:
		./$(BIN)$(EXEC) 10000000 $(CP_CLUSTERS)

runpar:
		./$(BIN)$(EXEC) 10000000 $(CP_CLUSTERS) $(THREADS)