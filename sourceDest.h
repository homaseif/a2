
void sourceDest(char *txt, int *src, int *dst){

	char *enumber1 = malloc(4 * sizeof(char));
        char *enumber2 = malloc(4 * sizeof(char));
        int i = 2;
        int iter = 0;
        while(txt[i] != ' '){
             enumber1[iter] = txt[i];
             iter++;
             i++;
	}
        *src = charToInt(enumber1, iter);
        free(enumber1);

        iter=0;
        i++;
        while(txt[i] != '\0'){
             enumber2[iter] = txt[i];
             iter++;
             i++;
	}
        *dst = charToInt(enumber2,iter);
        free(enumber2);

};
