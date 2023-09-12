#include <stdio.h>
void somProd(char a, char b, char* s, short* p);
int main() {
	printf("Somme et produit de 9 et 42\n");

/// Entrée des données
	char a = 9, b = 42;
	char s = 0;			// La somme
	short p = 0;		// Le produit
	
/// Traitement	
	somProd(a, b, &s, &p);

/// Sortie des résultats
	printf("La somme est %d, le produit est %d\n ", s, p);
	
	return 0;
}
void somProd(c
har a, char b, char* s, short* p){
	*s = a + b;
	*p = a * b;
}
