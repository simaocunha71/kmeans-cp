#!/bin/bash
#SBATCH --time=1:00
#SBATCH --ntasks=1
#SBATCH --partition=cpar
time mpirun -np 1 ./bin/k_means