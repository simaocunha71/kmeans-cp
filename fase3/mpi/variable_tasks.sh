clusters=4
points=10000000
threads=0
echo "Threads = $threads"
echo "Points = $points"
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done