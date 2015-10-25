#include <stdio.h>
#include <stdlib.h>

#include "extractVertexNumber.h"
#include "createMatrix.h"
#include "findShortestPath.h"
#include "sourceDest.h"
#include "charToInt.h" 

int main(int argc, char *argv[]){

int vertex = -1;
char tmp;
int flag = 0;
int **matrix;
int len;
char *text;
int count;

while ((tmp=getchar()) != EOF){
  //Get input, Store in text
  len = 1000;
  text = malloc(len * sizeof(char));
  count = 0;
  text[count] = tmp;
  count++;

  while ((tmp=getchar()) != '\n'){
       if (count >= len)
          text = realloc(text, (len += 10) * sizeof(char));
       text[count] = tmp;
       count++;
       text[count] = '\0';
  }

  //V command
  if(text[0] == 'V'){
	if(flag == 1){
		printf("Error: 'V' has already entered.\n");
		free(text);
		continue;
	}

  	int vcheck = extractVertexNumber(text, count);
	if(vcheck < 0){
		printf("Error: Set of vertices can not be negative.\n");
		free(text);
	}
	else{
		if(flag == 2 || flag == 3){
			//Free matrix
			int i;
			for(i = 0; i < vertex; i++)
				free(matrix[i]);
			free(matrix);
		}
		vertex = vcheck;
		flag = 1;
		free(text);

	}
  }

  //E command
  else if(text[0] == 'E'){
	if(flag == 0 || flag == 3 || flag == 2){
		printf("Error: 'V' has to  be entered before 'E'.\n");
		free(text);
		continue;
	}
	int err;
	matrix = (int **)malloc(vertex * sizeof(int*));
        int i;
        for (i = 0; i < vertex; i++)
        	matrix[i] = (int *)malloc(vertex * sizeof(int));

  	err = createMatrix(text, count, vertex, matrix);
	if(err == 1){
		free(text);
		//free matrix
		int j;
                for(j = 0; j < vertex; j++)
                      free(matrix[j]);
                free(matrix);
		continue;
	}
	else{
		flag = 2;
		free(text);
  }
}

  //S command
  else if(text[0] == 's'){
	if(flag == 0 || flag == 1){
		printf("Error: A graph is not specified completely.\n");
		free(text);
		continue;
	}
        //Get Source & Destination Vertices
	int src;
	int dest;
        sourceDest(text, &src, &dest);
	if( src >= vertex || dest >= vertex || src < 0 || dest < 0){
		printf("Error: Invalid value for the source or destination vertex. (Greater than the set of vertices or negative value)\n");
		free(text);
		continue;
 	}
	int **inWeightMat = (int **)malloc(vertex * sizeof(int*));
        int k;
        for(k = 0; k < vertex; k++)
        	inWeightMat[k] = (int *)malloc(vertex * sizeof(int));
	int m;
	int n;
	for(m = 0; m < vertex; m++)
	   	for(n = 0; n < vertex; n++){
             		inWeightMat[m][n] = matrix[m][n];
	      		if(matrix[m][n] == 0 && m != n )
		 		inWeightMat[m][n]=250000;
		}
	//Find shortest path
	findShortestPath(src, dest, inWeightMat, vertex);
	int l;
        for(l = 0; l < vertex; l++)
		free(inWeightMat[l]);
        free(inWeightMat);
        free(text);
  }
}

  int p;
  for(p = 0; p < vertex; p++)
  	free(matrix[p]);
  free(matrix);

  return 0;
}
