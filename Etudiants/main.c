#include "etudiant.h"

int main(){
	char* path = (char*)malloc(1000), *fichier = "etudiant.csv";
//	strcpy(path, getenv("PWD"));
//	strcat(path, "Olona_info.csv");
	Etudiant mit[100];
	int len = getInfo("Olona_info.txt", mit);
	printf("%d\n", len);
	qsort(mit, len, sizeof(Etudiant), comp);
	givenumber(mit, len);
//	qsort(mit, len, sizeof(int), compnumero);
	//printInfo(mit, len);
	writeInfo(fichier, mit, len);

	return 0;
}
