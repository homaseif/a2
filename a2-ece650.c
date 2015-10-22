
#include <stdio.h>
#include <stdlib.h>

#include "charToInt.h"
#include "createGraph.h"
#include "findShortestPath.h"
 

int main()
{
int vertex;
int **matrix;
char tmp;
while ((tmp=getchar()) != EOF)
{
  //Get input, Store in text
  int len = 1000;
  char *text = malloc(len * sizeof(char));
  int count=0;
  text[count] = tmp;
  count++;
  while ((tmp=getchar()) != '\n'){
       if (count >= len)
          text = realloc(text, (len+=10) * sizeof(char));
       text[count] = tmp;
       count++;
       text[count] = '\0';
  }

  //Create Graph
  if(text[0]=='V' || text[0]=='E'){
    createGraph(text, count, &vertex, matrix);
    free(text);
  }

  //Find Shortest Path
  if(text[0] == 's'){
        //Get Source & Destination Vertices
        char *enumber1=malloc(4*sizeof(char));
        char *enumber2=malloc(4*sizeof(char));
        int l=2;
        int iter=0;
        while(text[l]!=' '){
             enumber1[iter]=text[l];
             iter++;
             l++;}
	int src=charToInt(enumber1, iter);
        free(enumber1);
        if(src>=vertex){
           printf("Error: Vertex %d does not exist.\n",src);
              }

        iter=0;
        l++;
        while(text[l]!='\0'){
             enumber2[iter]=text[l];
             iter++;
             l++;}
	int dest=charToInt(enumber2,iter);
        free(enumber2);
        if(dest>=vertex){
          printf("Error: Vertex %d does not exist.\n",dest);
            }

	int **inWeightMat=(int **)malloc(vertex*sizeof(int*));
        int k;
        for(k=0; k<vertex; k++)
           inWeightMat[k]=(int *)malloc(vertex*sizeof(int));
	int i;
	int j;
	for(i=0; i<vertex; ++i)
	   for(j=0; j<vertex; ++j){
              inWeightMat[i][j]=matrix[i][j];
	      if(matrix[i][j]==0 && i!=j )
		 inWeightMat[i][j]=250000;}

	findShortestPath(src, dest, inWeightMat, &vertex);
        free(text);
  }
}

  return 0;
}
