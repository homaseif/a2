

int createMatrix(char *txt, int size, int vertex, int **mat){ 
      int err = 0;

      int j;
      int k;
      for (j = 0; j < vertex; j++){
         for (k = 0; k < vertex; k++){
	    if (j == k)
		mat[j][k] = 1;
	    else
            	mat[j][k] = 0;
	 }
      }

      int n = 3;
      while (n < size){
        char *node1 = malloc(4 * sizeof(char));
        char *node2 = malloc(4 * sizeof(char));

        if (txt[n] == '<'){
          int counter1 = 0;
          n++;
          while (txt[n] != ','){
               node1[counter1] = txt[n];
               counter1++;
               n++;
	  }
          int a;
          a = charToInt(node1,counter1);
          free(node1);

          if (a >= vertex){
            printf("Error: Vertex %d does not exist.\n", a);
	    err = 1;
            break;
          }

          n++;
          int counter2 = 0;
          while (txt[n] != '>'){
               node2[counter2] = txt[n];
               counter2++;
               n++;
	  }
          int b;
          b = charToInt(node2,counter2);
          free(node2);

          if (b >= vertex){
            printf("Error: Vertex %d does not exist.\n", b);
	    err = 1;
            break;
          }

          mat[a][b] = 1;
          mat[b][a] = 1;
          n = n + 2;
        }
      }
    return err;
};
