void findShortestPath(int source, int destination, int **weightMatrix, int vertex){
        int current;
        int newCurr;
        int tmp1;
        int tmp2;
        int *parent = malloc(vertex * sizeof(int));
        int *distance = malloc(vertex * sizeof(int));
        int *visited = malloc(vertex * sizeof(int));
        int *result = malloc(vertex * sizeof(int));
        int i;
        int j;
        int flag = 1;
        for(i = 0; i < vertex; i++){
            visited[i] = 0;
            distance[i] = 250000;
            parent[i] = -1;
	}
        current = source;
        visited[current] = 1;
        distance[current] = 0;
        while(visited[destination] == 0){
              tmp1 = 250000;
              newCurr = source;
              for(i = 0; i < vertex; i++){
                  tmp2 = distance[current] + weightMatrix[current][i];
                  if(tmp2 < distance[i] && visited[i] == 0){
                     distance[i] = tmp2;
                     parent[i] = current;
		  }
                  if(tmp1 > distance[i] && visited[i] == 0){
                     tmp1 = distance[i];
                     newCurr = i;
		  }
              }
              if(current == newCurr){
                 printf("Error: There is no path between %d and %d vertices.\n", source, destination);
                 flag = 0;
                 break;
	      }
              current = newCurr;
              visited[current] = 1;
        }
        current = destination;
        j = 0;
        while(current != -1){
              result[j] = current;
              current = parent[current];
              j++;
	}
        int q;
        for(q = j - 1; q > 0; q--){
           printf("%d-", result[q]);
        }
        if(flag == 1)
          printf("%d\n",result[0]);
        free(parent);
        free(distance);
        free(visited);
        free(result);
};
