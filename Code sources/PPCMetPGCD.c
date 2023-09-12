#include <stdio.h>

void getData(int* a, int* b);
int calculPGCD(int a, int b);
int calculPPCM(int a, int b, int pgcd);

int main(){
	printf("PGCD et PPCM de deux nombres a et b \n");

/// Déclaration des variables
	int 	a=0, b=0,	// Les nombres à trouver le PGCD et le PPCM
		pgcd=0,		// La valeur du PGCD de a et b
		ppcm=0;		// La valeur de PPCM de a et b

	getData(&a, &b);

/// Traitement
	pgcd = calculPGCD(a, b);
	ppcm = calculPPCM(a, b, pgcd);

/// Sortie des résultats
	printf("Le PGCD(%d, %d) = %d\n", a, b, pgcd);
	printf("Le PPCM(%d, %d) = %d\n", a, b, ppcm);
	return 0;
}

// Fonction qui permet de prendre les valeurs de a et b
void getData(int* a, int* b){
	printf("Entrer le nombre a : ");
	scanf("%d", a);

	printf("Entrer le nombre b : ");
	scanf("%d", b);
}

// Fonction qui permet de calculer le PGCD de a et b
int  calculPGCD(int a, int b){
	int pgcd = 0;

	for(int i=1; i<=b, i<=a; i++){
		if(b%i==0 && a%i==0){
			pgcd=i;
		}
	}

	return pgcd;
}

// Fonction qui permet de calculer le PPCM de a et b
int calculPPCM(int a, int b, int pgcd){
	int ppcm = 0;

	ppcm = ((a*b)/pgcd);

	return ppcm;
}
