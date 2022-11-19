#!/bin/bash

module load gcc/7.2.0
echo "------------N_THREADS = 2------------"
time ./bin/k_means 10000000 32 2
#echo "------------N_THREADS = 4------------"
#time ./bin/k_means 10000000 32 4
#echo "------------N_THREADS = 6------------"
#time ./bin/k_means 10000000 32 6
#echo "------------N_THREADS = 8------------"
#time ./bin/k_means 10000000 32 8
#echo "------------N_THREADS = 10------------"
#time ./bin/k_means 10000000 32 10
#echo "------------N_THREADS = 12------------"
#time ./bin/k_means 10000000 32 12
#echo "------------N_THREADS = 14------------"
#time ./bin/k_means 10000000 32 14
#echo "------------N_THREADS = 16------------"
#time ./bin/k_means 10000000 32 16
#echo "------------N_THREADS = 18------------"
#time ./bin/k_means 10000000 32 18
#echo "------------N_THREADS = 20------------"
#time ./bin/k_means 10000000 32 20
#echo "------------N_THREADS = 22------------"
#time ./bin/k_means 10000000 32 22
#echo "------------N_THREADS = 24------------"
#time ./bin/k_means 10000000 32 24
#echo "------------N_THREADS = 26------------"
#time ./bin/k_means 10000000 32 26
#echo "------------N_THREADS = 28------------"
#time ./bin/k_means 10000000 32 28
#echo "------------N_THREADS = 30------------"
#time ./bin/k_means 10000000 32 30
#echo "------------N_THREADS = 32------------"
#time ./bin/k_means 10000000 32 32
#echo "------------N_THREADS = 34------------"
#time ./bin/k_means 10000000 32 34
#echo "------------N_THREADS = 36------------"
#time ./bin/k_means 10000000 32 36
#echo "------------N_THREADS = 38------------"
#time ./bin/k_means 10000000 32 38
#echo "------------N_THREADS = 40------------"
#time ./bin/k_means 10000000 32 40
#