#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int n=0;	/// Le nombre entre 1 à 100 à trouver
	int nombre=0;	/// Le nombre entré par le joueur

/// Entrée des données
	printf("\t**Bienvenu dans le jeu de devinette**\n");
	srand(time(NULL));
	n = 1+ (int)(100.0*rand() / (RAND_MAX + 1.0));	// Le nombre pseudo-aléatoire de 1 à 100 généré par l'ordinateur

/// Traitement et Sortie des données
	for (int i=1; i<9; i++){
		printf("Donnez un nombre : ");
		scanf("%d", &nombre);
		if(nombre>n){
			printf("Trop grand !\n");
			if(7-i != 0)
				printf("Vous avez encore %d coup(s)\n", 7-i);
			else
				printf("Vous n'avez plus d'essai\n");
		}
		if(nombre<n){
			printf("Trop petit !\n");
			if(7-i != 0)
				printf("Vous avez encore %d essai(s)\n", 7-i);
			else
				printf("Vous n'avez plus d'essai\n");
		}
		if(nombre==n){
			printf("Bravo, vous avez gagné!\n");
			break;
		}
		if(i==7){
			printf("Vous avez perdu!\n");
			break;
		}
	}
	return 0;
}
