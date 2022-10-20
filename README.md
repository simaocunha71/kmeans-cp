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

    #CALCULO DE CENTROIDS

    DEPOIS V4:

    for(int j = 0; j < N_SAMPLES, j++){
        for(int i = 0; i < K_CLUSTERS; i++){
            #COMPARA DIST ENTRE CLUSTER E SPACE_POINT SE MENOR ASSIGN
        }
        #GUARDA NO CLUSTER MAIS PERTO DO TEMPO A SOMA DE X e Y
    }

    #DIVIDE AS SOMAS DE X e Y DE CADA CLUSTER PELO Nº DE PONTOS
