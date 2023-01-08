#!/bin/bash
#SBATCH --time=3:00
#SBATCH --ntasks=30
#SBATCH --partition=cpar

echo "Setting clusters to K = 4"
echo "--------------------- 2 TASKS ---------------------"
time mpirun -np 2 ./bin/k_means 10000000 4
echo "--------------------- 4 TASKS ---------------------"
time mpirun -np 4 ./bin/k_means 10000000 4
echo "--------------------- 6 TASKS ---------------------"
time mpirun -np 6 ./bin/k_means 10000000 4
echo "--------------------- 8 TASKS ---------------------"
time mpirun -np 8 ./bin/k_means 10000000 4
echo "--------------------- 10 TASKS ---------------------"
time mpirun -np 10 ./bin/k_means 10000000 4
echo "--------------------- 12 TASKS ---------------------"
time mpirun -np 12 ./bin/k_means 10000000 4
echo "--------------------- 14 TASKS ---------------------"
time mpirun -np 14 ./bin/k_means 10000000 4
echo "--------------------- 16 TASKS ---------------------"
time mpirun -np 16 ./bin/k_means 10000000 4
echo "--------------------- 18 TASKS ---------------------"
time mpirun -np 18 ./bin/k_means 10000000 4
echo "--------------------- 20 TASKS ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 4
echo "--------------------- 22 TASKS ---------------------"
time mpirun -np 22 ./bin/k_means 10000000 4
echo "--------------------- 24 TASKS ---------------------"
time mpirun -np 24 ./bin/k_means 10000000 4
echo "--------------------- 26 TASKS ---------------------"
time mpirun -np 26 ./bin/k_means 10000000 4
echo "--------------------- 28 TASKS ---------------------"
time mpirun -np 28 ./bin/k_means 10000000 4
echo "--------------------- 30 TASKS ---------------------"
time mpirun -np 30 ./bin/k_means 10000000 4

echo "Setting clusters to K = 32"
echo "--------------------- 2 TASKS ---------------------"
time mpirun -np 2 ./bin/k_means 10000000 32
echo "--------------------- 4 TASKS ---------------------"
time mpirun -np 4 ./bin/k_means 10000000 32
echo "--------------------- 6 TASKS ---------------------"
time mpirun -np 6 ./bin/k_means 10000000 32
echo "--------------------- 8 TASKS ---------------------"
time mpirun -np 8 ./bin/k_means 10000000 32
echo "--------------------- 10 TASKS ---------------------"
time mpirun -np 10 ./bin/k_means 10000000 32
echo "--------------------- 12 TASKS ---------------------"
time mpirun -np 12 ./bin/k_means 10000000 32
echo "--------------------- 14 TASKS ---------------------"
time mpirun -np 14 ./bin/k_means 10000000 32
echo "--------------------- 16 TASKS ---------------------"
time mpirun -np 16 ./bin/k_means 10000000 32
echo "--------------------- 18 TASKS ---------------------"
time mpirun -np 18 ./bin/k_means 10000000 32
echo "--------------------- 20 TASKS ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 32
echo "--------------------- 22 TASKS ---------------------"
time mpirun -np 22 ./bin/k_means 10000000 32
echo "--------------------- 24 TASKS ---------------------"
time mpirun -np 24 ./bin/k_means 10000000 32
echo "--------------------- 26 TASKS ---------------------"
time mpirun -np 26 ./bin/k_means 10000000 32
echo "--------------------- 28 TASKS ---------------------"
time mpirun -np 28 ./bin/k_means 10000000 32
echo "--------------------- 30 TASKS ---------------------"
time mpirun -np 30 ./bin/k_means 10000000 32

