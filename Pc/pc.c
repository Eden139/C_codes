#include "pc.h"
int comparaison(const void *a, const void *b){
	return strcmp(((Pc *)a)->ethiquette, ((Pc *)b)->ethiquette);
}
int getInfo(char* pathToFile, Pc *mit){
// Déclarations
	FILE *info = fopen(pathToFile, "r");
	char row[256];
	int i = 0;

// Traitements
	for(; fgets(row, 255, info) != NULL; i++){
		row[strcspn(row, "\n")] = '\0';
		for(char *t = strtok(row, ";"), j = 0; t; t = strtok(0, ";"), j++)
			strcpy(((char(*)[40])&mit[i])[j], t);
	}
	return i;
}
void writeInfo(char *file, Pc *mit, size_t len){
	FILE *fic = fopen(file, "w");
	if (fic == NULL){
		perror("Impossible à ouvrir");
		exit(1);
	}
	fprintf(fic, "MAC|ETHIQUETTE|MARQUE\n");
	for(int i = 0; i < len; i++)
		fprintf(fic, "%s|%s|%s\n", mit[i].mac, mit[i].ethiquette, mit[i].marque);
}
void printInfo(Pc *mit, size_t len){
	for(int i = 0; i < len; i++)
		printf("%s|%s|%s\n", mit[i].mac, mit[i].ethiquette, mit[i].marque);
}
