

/* This is a function to create the graph by extracting the vertex number and edges from the user input.
The inputs to the function are an array of characters of the user input, size of the array, the address
of "vertex" variable and the pointer to the adjacent matrix of the graph. */

void createGraph (char *txt, int size, int* vertex, int **matrix)
{

  //Extract the number of vertices and store it in vertex
  if (txt[0] == 'V')
  {
    char *vnumber = malloc( (size-2) * sizeof(char) );
    int i;
    for (i = 2; i < size; ++i)
       vnumber[i-2] = txt[i];
    *vertex = charToInt(vnumber, size-2);
    free(vnumber);
    }

    //Extract edges and store them in an adjacent matrix
    else if (txt[0] == 'E')
    {
      matrix = (int **)malloc(*vertex * sizeof(int*));
      int j;
      for (j = 0; j < *vertex; ++j)
         matrix[j] = (int *)malloc(*vertex * sizeof(int));

      int k;
      int l;
      for (k = 0; k < *vertex; ++k)
      {
         for (l = 0; l < *vertex; ++l)
	 {
	    if (l == k)
		matrix[k][l] = 1;
	    else
            	matrix[k][l] = 0;
	 }
      }

      int n = 3;
      while (n < size)
      {
        char *node1 = malloc(5 * sizeof(char));
        char *node2 = malloc(5 * sizeof(char));

        if (txt[n] == '<')
        {
          int counter1=0;
          n++;
          while (txt[n] != ',')
	  {
               node1[counter1] = txt[n];
               counter1++;
               n++;
	  }
          int a;
          a = charToInt(node1,counter1);
          free(node1);

          if (a >= *vertex)
          {
            printf("Error: Vertex %d does not exist.\n", a);
            break;
          }

          n++;
          int counter2=0;
          while (txt[n] != '>')
	  {
               node2[counter2] = txt[n];
               counter2++;
               n++;
	  }
          int b;
          b = charToInt(node2,counter2);
          free(node2);

          if (b >= *vertex)
	  {
            printf("Error: Vertex %d does not exist.\n", b);
            break;
          }

          matrix[a][b] = 1;
          matrix[b][a] = 1;
          n = n + 2;
        }
      }
    }
}

