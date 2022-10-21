CC=gcc
CFLAGS=-Wall -O2

all: v1 v2 v3 v4 v5


v1: v1/src/k_means.c
	@echo "> Compiling V1..."
	$(CC) $(CFLAGS) -c v1/src/utils.c -o v1/bin/utils.o
	$(CC) $(CFLAGS) v1/src/k_means.c v1/bin/utils.o -o v1/bin/kmeans -lm



v2: v2/src/k_means.c
	@echo "> Compiling V2..."
	$(CC) $(CFLAGS) -c v2/src/utils.c -o v2/bin/utils.o
	$(CC) $(CFLAGS) v2/src/k_means.c v2/bin/utils.o -o v2/bin/kmeans -lm



v3: v3/src/k_means.c
	@echo "> Compiling V3..."
	$(CC) $(CFLAGS) -c v3/src/utils.c -o v3/bin/utils.o
	$(CC) $(CFLAGS) v3/src/k_means.c v3/bin/utils.o -o v3/bin/kmeans



v4: v4/src/k_means.c
	@echo "> Compiling V4..."
	$(CC) $(CFLAGS) -c v4/src/utils.c -o v4/bin/utils.o
	$(CC) $(CFLAGS) v4/src/k_means.c v4/bin/utils.o -o v4/bin/kmeans



v5: v5/src/k_means.c
	@echo "> Compiling V5..."
	$(CC) $(CFLAGS) -c v5/src/utils.c -o v5/bin/utils.o
	$(CC) $(CFLAGS) v5/src/k_means.c v5/bin/utils.o -o v5/bin/kmeans
