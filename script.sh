#!/bin/bash
#SBATCH --time=1:00
#SBATCH --ntasks=20
#SBATCH --partition=cpar
echo "--------------------- 2 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 2
echo "--------------------- 4 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 4
echo "--------------------- 6 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 6
echo "--------------------- 8 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 8
echo "--------------------- 10 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 10
echo "--------------------- 12 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 12
echo "--------------------- 14 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 14
echo "--------------------- 16 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 16
echo "--------------------- 18 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 18
echo "--------------------- 20 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 20
echo "--------------------- 22 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 22
echo "--------------------- 24 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 24
echo "--------------------- 26 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 26
echo "--------------------- 28 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 28
echo "--------------------- 30 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 30
echo "--------------------- 32 clusters ---------------------"
time mpirun -np 20 ./bin/k_means 10000000 32