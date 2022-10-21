# kmeans-cp
 
v1 : start algorithm with structs
v2 : remove structs and use only arrays
v3 : remove sqrt (unecessary because compare is equal) and change pow to multiply by itself (because pow(x,2) = x*x)
v4 : faz o calculo dos centroid enquando dá assign dos pontos. Agora esse assign acontece percorrendo em cada ponto, todos os clusters, enquanto antes percorria em cada cluster, todos os pontos.


    ANTES V4:

    for(int i = 0; i < K_CLUSTERS, i++){
        for(int j = 0; j < N_SAMPLES; j++){
            #COMPARA DIST ENTRE CLUSTER E SPACE_POINT SE MENOR ASSIGN
        }
    }

    #CALCULO DE CENTROIDS NOUTRA FUNÇÃO

    DEPOIS V4:

    for(int j = 0; j < N_SAMPLES, j++){
        for(int i = 0; i < K_CLUSTERS; i++){
            #COMPARA DIST ENTRE CLUSTER E SPACE_POINT SE MENOR ASSIGN
        }
        #GUARDA NO CLUSTER MAIS PERTO DO TEMPO A SOMA DE X e Y
    }

    #DIVIDE AS SOMAS DE X e Y DE CADA CLUSTER PELO Nº DE PONTOS

v5: Em vez de 2 arrays (um para x e outro para o y) é apenas 1 e são guardados aos pares [x1,y1,x2,y2,...xn,yn].


scp -r <source> a93277@s7edu2.di.uminho.pt:
PjeW46ic

ssh s7edu2.di.uminho.pt -l a93277
PjeW46ic

module load gcc/7.2.0

srun --partition=cpar perf stat -e instructions,cycles make run

srun --partition=cpar perf stat -e L1-dcache-load-misses,instructions,cycles  -M cpi  make run


v1:
       761556501      L1-dcache-load-misses
       42483143149      instructions              #    0.80  insn per cycle
       53237284921      cycles
       42483143149      inst_retired.any          #      1.3 CPI
       53237284885      cycles

       16.333599106 seconds time elapsed

       16.271159000 seconds user
       0.062003000 seconds sys

v2:
       552567852      L1-dcache-load-misses
       40878639368      instructions              #    0.79  insn per cycle
       51679749816      cycles
       40878639368      inst_retired.any          #      1.3 CPI
       51679749774      cycles

       15.664771910 seconds time elapsed

       15.629199000 seconds user
       0.033943000 seconds sys

v3:
       555936886      L1-dcache-load-misses
       29651173886      instructions              #    0.98  insn per cycle
       30207337114      cycles
       29651173886      inst_retired.any          #      1.0 CPI
       30207337063      cycles

       9.617327532 seconds time elapsed

       9.570152000 seconds user
       0.045490000 seconds sys

v4:
       59129117      L1-dcache-load-misses
       29121513027      instructions              #    2.07  insn per cycle
       14074185656      cycles
       29121513027      inst_retired.any          #      0.5 CPI
       14074185608      cycles

       4.418378914 seconds time elapsed

       4.394721000 seconds user
       0.021842000 seconds sys

v5:
       53585435      L1-dcache-load-misses
       29115427751      instructions              #    2.15  insn per cycle
       13516177816      cycles
       29115427751      inst_retired.any          #      0.5 CPI
       13516177786      cycles

       4.420241992 seconds time elapsed

       4.396548000 seconds user
       0.023117000 seconds sys
    
v6:
       53553060      L1-dcache-load-misses
       29118912876      instructions              #    2.15  insn per cycle
       13525506172      cycles
       29118912876      inst_retired.any          #      0.5 CPI
       13525506133      cycles

       4.401342738 seconds time elapsed

       4.376189000 seconds user
       0.023453000 seconds sys




