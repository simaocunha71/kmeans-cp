clusters=128
points=10000000
echo "Points = $points"
echo "Clusters = $clusters"
echo "------------CLUSTERS = 128------------"
for threads in 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40; do
    echo "------------N_THREADS = $threads------------"
	time ./bin/k_means $points $clusters $threads
done