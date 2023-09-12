#include <stdio.h>
void remplir_tableau(long long tab[][5], unsigned n, unsigned m);
void affiche_tableau(long long (*tab)[5], unsigned n, unsigned m);

int main(){
	long long tab[5][5];	// Le tableau

/* Fonction pour remplir le tableau */
	remplir_tableau(tab, 5, 5);

/* Fonction pour afficher les éléments du tableau */
	affiche_tableau(tab, 5, 5);

	return 0;
}

void remplir_tableau(long long tab[][5], unsigned n, unsigned m){
	for(unsigned long i = 0; i < n; i++){
		for(unsigned j = 0; j < m; j++){
			printf("Entrez tab[%lu][%u]: ", i, j);
			scanf("%lld", &tab[i][j]);
		}
	}
}

void affiche_tableau(long long (*tab)[5], unsigned n, unsigned m){
       for(unsigned short i = 0; i < n; i++){
		for(unsigned long long j = 0; j < m; j++)
	 		printf("%lld ", tab[i][j]);
		printf("\n");
 	}
}
