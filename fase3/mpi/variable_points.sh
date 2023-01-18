#!/bin/bash
#SBATCH --time=5:00
#SBATCH --ntasks=40
#SBATCH --partition=cpar

tasks=4
clusters=4
threads=2
echo "Threads = $threads"
echo "Clusters = $clusters"
echo "Tasks = $tasks"

for points in 100000 500000 1000000 5000000 10000000 50000000 100000000; do
    echo "--------------------- $points Points ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done
