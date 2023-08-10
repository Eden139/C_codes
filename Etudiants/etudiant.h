#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nom[256];
	char prenom[256];
	int numero;
	char tel[256];
	char email[256];
	char adresse[256];
	char date[256];
	char lieu[256];
	char bacc[256];
	char genre[256];
	char cin[256];
	char github[256];
} Etudiant;
int comp(const void *a, const void *b);
int compnumero(const void*a, const void *b);
void givenumber(Etudiant *mit, size_t len);
int getInfo(char* path,Etudiant *mit);
void printInfo(Etudiant *mit, size_t len);
void writeInfo(char* file, Etudiant *mit, size_t len);
