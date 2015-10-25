
int extractVertexNumber(char *txt, int size){

//Extract the number of vertices and store it in vertex
    int vertex;
    char *vnumber = malloc( (size-2) * sizeof(char) );
    int i;
    for (i = 2; i < size; i++)
       vnumber[i-2] = txt[i];
    vertex = charToInt(vnumber, size-2);
    free(vnumber);
    return vertex;
};
