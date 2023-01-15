#!/bin/bash
#SBATCH --time=5:00
#SBATCH --ntasks=40
#SBATCH --partition=cpar

clusters=4
points=10000000
task=2
echo "Tasks = $tasks"
echo "Points = $points"
echo "Clusters = $clusters"

for threads in 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40; do
    echo "--------------------- $threads Threads ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done