#!/bin/bash

module load gcc/7.2.0
echo "------------N_THREADS = 2------------"
time ./bin/k_means 10000000 4 2
echo "------------N_THREADS = 4------------"
time ./bin/k_means 10000000 4 4
echo "------------N_THREADS = 6------------"
time ./bin/k_means 10000000 4 6
echo "------------N_THREADS = 8------------"
time ./bin/k_means 10000000 4 8
echo "------------N_THREADS = 10------------"
time ./bin/k_means 10000000 4 10
echo "------------N_THREADS = 12------------"
time ./bin/k_means 10000000 4 12
echo "------------N_THREADS = 14------------"
time ./bin/k_means 10000000 4 14
echo "------------N_THREADS = 16------------"
time ./bin/k_means 10000000 4 16
echo "------------N_THREADS = 18------------"
time ./bin/k_means 10000000 4 18
echo "------------N_THREADS = 20------------"
time ./bin/k_means 10000000 4 20
echo "------------N_THREADS = 22------------"
time ./bin/k_means 10000000 4 22
echo "------------N_THREADS = 24------------"
time ./bin/k_means 10000000 4 24
echo "------------N_THREADS = 26------------"
time ./bin/k_means 10000000 4 26
echo "------------N_THREADS = 28------------"
time ./bin/k_means 10000000 4 28
echo "------------N_THREADS = 30------------"
time ./bin/k_means 10000000 4 30
echo "------------N_THREADS = 4------------"
time ./bin/k_means 10000000 4 4
echo "------------N_THREADS = 34------------"
time ./bin/k_means 10000000 4 34
echo "------------N_THREADS = 36------------"
time ./bin/k_means 10000000 4 36
echo "------------N_THREADS = 38------------"
time ./bin/k_means 10000000 4 38
echo "------------N_THREADS = 40------------"
time ./bin/k_means 10000000 4 40
