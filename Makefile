V1=v1/
V2=v2/
V3=v3/
V4=v4/
V5=v5/
V6=v6/
V7=v7/
CC=gcc
BIN=bin/
SRC=src/
INCLUDES=include/
EXEC=k_means
CFLAGS=-Wall -O2
.DEFAULT_GOAL=all	

clean: clean-v1 clean-v2 clean-v3 clean-v4 clean-v5 clean-v6 clean-v7
all: v1 v2 v3 v4 v5 v6 v7
run: run-v1 run-v2 run-v3 run-v4 run-v5 run-v6 run-v7

v1:$(V1)$(SRC)k_means.c $(V1)$(BIN)utils.o
		$(CC) $(CFLAGS) $(V1)$(SRC)k_means.c $(V1)$(BIN)utils.o -o $(V1)$(BIN)$(EXEC) -lm
		
$(V1)$(BIN)utils.o: $(V1)$(SRC)utils.c $(V1)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(V1)$(SRC)utils.c -o $(V1)$(BIN)utils.o

v2:$(V2)$(SRC)k_means.c $(V2)$(BIN)utils.o
		$(CC) $(CFLAGS) $(V2)$(SRC)k_means.c $(V2)$(BIN)utils.o -o $(V2)$(BIN)$(EXEC) -lm
		
$(V2)$(BIN)utils.o: $(V2)$(SRC)utils.c $(V2)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(V2)$(SRC)utils.c -o $(V2)$(BIN)utils.o
	
v3:$(V3)$(SRC)k_means.c $(V3)$(BIN)utils.o
		$(CC) $(CFLAGS) $(V3)$(SRC)k_means.c $(V3)$(BIN)utils.o -o $(V3)$(BIN)$(EXEC)
		
$(V3)$(BIN)utils.o: $(V3)$(SRC)utils.c $(V3)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(V3)$(SRC)utils.c -o $(V3)$(BIN)utils.o

v4:$(V4)$(SRC)k_means.c $(V4)$(BIN)utils.o
		$(CC) $(CFLAGS) $(V4)$(SRC)k_means.c $(V4)$(BIN)utils.o -o $(V4)$(BIN)$(EXEC)
		
$(V4)$(BIN)utils.o: $(V4)$(SRC)utils.c $(V4)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(V4)$(SRC)utils.c -o $(V4)$(BIN)utils.o

v5:$(V5)$(SRC)k_means.c $(V5)$(BIN)utils.o
		$(CC) $(CFLAGS) $(V5)$(SRC)k_means.c $(V5)$(BIN)utils.o -o $(V5)$(BIN)$(EXEC)
		
$(V5)$(BIN)utils.o: $(V5)$(SRC)utils.c $(V5)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(V5)$(SRC)utils.c -o $(V5)$(BIN)utils.o

v6:$(V6)$(SRC)k_means.c $(V6)$(BIN)utils.o
		$(CC) $(CFLAGS) $(V6)$(SRC)k_means.c $(V6)$(BIN)utils.o -o $(V6)$(BIN)$(EXEC)
		
$(V6)$(BIN)utils.o: $(V6)$(SRC)utils.c $(V6)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(V6)$(SRC)utils.c -o $(V6)$(BIN)utils.o

v7:$(V7)$(SRC)k_means.c $(V7)$(BIN)utils.o
		$(CC) $(CFLAGS) $(V7)$(SRC)k_means.c $(V7)$(BIN)utils.o -o $(V7)$(BIN)$(EXEC)
		
$(V7)$(BIN)utils.o: $(V7)$(SRC)utils.c $(V7)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(V7)$(SRC)utils.c -o $(V7)$(BIN)utils.o

clean-v1:
		rm -r $(V1)bin/*
clean-v2:
		rm -r $(V2)bin/*
clean-v3:
		rm -r $(V3)bin/*
clean-v4:
		rm -r $(V4)bin/*
clean-v5:
		rm -r $(V5)bin/*
clean-v6:
		rm -r $(V6)bin/*
clean-v7:
		rm -r $(V7)bin/*

run-v1:
		time ./$(V1)$(BIN)$(EXEC)
run-v2:
		time ./$(V2)$(BIN)$(EXEC)
run-v3:
		time ./$(V3)$(BIN)$(EXEC)
run-v4:
		time ./$(V4)$(BIN)$(EXEC)
run-v5:
		time ./$(V5)$(BIN)$(EXEC)
run-v6:
		time ./$(V6)$(BIN)$(EXEC)
run-v7:
		time ./$(V7)$(BIN)$(EXEC)

