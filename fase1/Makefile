VA=va/
VB=vb/
VC=vc/
VD=vd/
VE=ve/
VF2=vf-2/
VF4=vf-4/
CC=gcc
BIN=bin/
SRC=src/
INCLUDES=include/
EXEC=k_means
CFLAGS=-Wall -O2
.DEFAULT_GOAL=all	

clean: clean-va clean-vb clean-vc clean-vd clean-ve clean-vf2 clean-vf4
all: va vb vc vd ve vf2 vf4
run: run-va run-vb run-vc run-vd run-ve run-vf2 run-vf4

va:$(VA)$(SRC)k_means.c $(VA)$(BIN)utils.o
		$(CC) $(CFLAGS) $(VA)$(SRC)k_means.c $(VA)$(BIN)utils.o -o $(VA)$(BIN)$(EXEC) -lm
		
$(VA)$(BIN)utils.o: $(VA)$(SRC)utils.c $(VA)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(VA)$(SRC)utils.c -o $(VA)$(BIN)utils.o

vb:$(VB)$(SRC)k_means.c $(VB)$(BIN)utils.o
		$(CC) $(CFLAGS) $(VB)$(SRC)k_means.c $(VB)$(BIN)utils.o -o $(VB)$(BIN)$(EXEC) -lm
		
$(VB)$(BIN)utils.o: $(VB)$(SRC)utils.c $(VB)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(VB)$(SRC)utils.c -o $(VB)$(BIN)utils.o
	
vc:$(VC)$(SRC)k_means.c $(VC)$(BIN)utils.o
		$(CC) $(CFLAGS) $(VC)$(SRC)k_means.c $(VC)$(BIN)utils.o -o $(VC)$(BIN)$(EXEC)
		
$(VC)$(BIN)utils.o: $(VC)$(SRC)utils.c $(VC)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(VC)$(SRC)utils.c -o $(VC)$(BIN)utils.o

vd:$(VD)$(SRC)k_means.c $(VD)$(BIN)utils.o
		$(CC) $(CFLAGS) $(VD)$(SRC)k_means.c $(VD)$(BIN)utils.o -o $(VD)$(BIN)$(EXEC)
		
$(VD)$(BIN)utils.o: $(VD)$(SRC)utils.c $(VD)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(VD)$(SRC)utils.c -o $(VD)$(BIN)utils.o

ve:$(VE)$(SRC)k_means.c $(VE)$(BIN)utils.o
		$(CC) $(CFLAGS) $(VE)$(SRC)k_means.c $(VE)$(BIN)utils.o -o $(VE)$(BIN)$(EXEC)
		
$(VE)$(BIN)utils.o: $(VE)$(SRC)utils.c $(VE)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(VE)$(SRC)utils.c -o $(VE)$(BIN)utils.o

vf2:$(VF2)$(SRC)k_means.c $(VF2)$(BIN)utils.o
		$(CC) $(CFLAGS) $(VF2)$(SRC)k_means.c $(VF2)$(BIN)utils.o -o $(VF2)$(BIN)$(EXEC)
		
$(VF2)$(BIN)utils.o: $(VF2)$(SRC)utils.c $(VF2)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(VF2)$(SRC)utils.c -o $(VF2)$(BIN)utils.o

vf4:$(VF4)$(SRC)k_means.c $(VF4)$(BIN)utils.o
		$(CC) $(CFLAGS) $(VF4)$(SRC)k_means.c $(VF4)$(BIN)utils.o -o $(VF4)$(BIN)$(EXEC)
		
$(VF4)$(BIN)utils.o: $(VF4)$(SRC)utils.c $(VF4)$(INCLUDES)utils.h
		$(CC) $(CFLAGS) -c $(VF4)$(SRC)utils.c -o $(VF4)$(BIN)utils.o


clean-va:
		rm -r $(VA)bin/*
clean-vb:
		rm -r $(VB)bin/*
clean-vc:
		rm -r $(VC)bin/*
clean-vd:
		rm -r $(VD)bin/*
clean-ve:
		rm -r $(VE)bin/*
clean-vf2:
		rm -r $(VF2)bin/*
clean-vf4:
		rm -r $(VF4)bin/*

run-va:
		time ./$(VA)$(BIN)$(EXEC)
run-vb:
		time ./$(VB)$(BIN)$(EXEC)
run-vc:
		time ./$(VC)$(BIN)$(EXEC)
run-vd:
		time ./$(VD)$(BIN)$(EXEC)
run-ve:
		time ./$(VE)$(BIN)$(EXEC)
run-vf2:
		time ./$(VF2)$(BIN)$(EXEC)
run-vf4:
		time ./$(VF4)$(BIN)$(EXEC)
