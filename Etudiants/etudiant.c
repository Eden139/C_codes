#include "etudiant.h"
int comp(const void *a, const void *b) {
    int test = strcmp(((const Etudiant*)a)->nom, ((const Etudiant*)b)->nom);
    return test == 0 ? strcmp(((const Etudiant*)a)->prenom, ((const Etudiant*)b)->prenom) : test;
}
void givenumber(Etudiant *mit, size_t len){
	for(int i = 0; i < len; i++)
		mit[i].numero = i + 1;
}
int compnumero(const void *a, const void *b){
	return ((Etudiant *)a)->numero -((Etudiant*)b)->numero;
}
int getInfo(char* pathToFile, Etudiant *mit) {
    FILE *info = fopen(pathToFile, "r");
    if (info == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }
    char row[2048];
    int i = 0;
    for (; fgets(row, sizeof(row), info) != NULL; i++) {
	    row[strcspn(row, "\n")] = 0;
	    int j = 0;
	    for(char * t = strtok(row, ","); t; t = strtok(0, ","), j++){
		    if(j == 2)
			    mit[i].numero = atoi(t);
		    else strcpy(((char(*)[256])&mit[i])[j], t);
		}
		
    }
    fclose(info);
    return i;
}
void printInfo(Etudiant *mit, size_t len){
	putchar(10);
	 for(int i = 0; i < len; i++){
                printf("%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", mit[i].nom, mit[i].prenom, mit[i].numero, mit[i].tel, mit[i].email, mit[i].adresse, mit[i].date, mit[i].lieu, mit[i].bacc, mit[i].genre, mit[i].cin, mit[i].github);
        }
}
void writeInfo(char* file, Etudiant *mit, size_t len){
	FILE * fichier = fopen(file, "w");
	if(fichier == NULL){
		perror("Erreur\n");
		exit(1);
	}
	for(int i = 0; i < len; i++){
		fprintf(fichier, "%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", mit[i].nom, mit[i].prenom, mit[i].numero, mit[i].tel, mit[i].email, mit[i].adresse, mit[i].date, mit[i].lieu, mit[i].bacc, mit[i].genre, mit[i].cin, mit[i].github);
	}
}
