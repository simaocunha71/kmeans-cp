#!/bin/bash
#SBATCH --time=5:00
#SBATCH --ntasks=40
#SBATCH --partition=cpar

tasks=4
points=10000000
threads=2
echo "Threads = $threads"
echo "Points = $points"
echo "Tasks = $tasks"

for clusters in 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40; do
    echo "--------------------- $clusters Clusters ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done
