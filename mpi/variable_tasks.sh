clusters=4
points=10000000
threads=4
echo "Threads = $threads"
echo "Points = $points"
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

clusters=32
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

clusters=64
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

clusters=128
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

threads=10
echo "Threads = $threads"
clusters=4
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

clusters=32
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

clusters=64
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

clusters=128
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

threads=8
echo "Threads = $threads"
clusters=4
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

clusters=32
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

clusters=64
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done

clusters=128
echo "Clusters = $clusters"

for task in 2 4 6 8 10 12 14 16 18 20; do
    echo "--------------------- $task Tasks ---------------------"
    time mpirun -np $task ./bin/k_means $points $clusters $threads
done