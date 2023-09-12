#include <stdio.h>
int main() {
	printf("Somme et produit de 9 et 42\n");

/// Entrée des données
	char a = 9, b = 42;
	char s = 0;			// La somme
	short p = 0;		// Le produit
	
/// Traitement	
	s = a + b;
	p = a * b;
	
/// Sortie des résultats
	printf("La somme est %d, le produit est %d\n ", s, p);
	
	return 0;
}
