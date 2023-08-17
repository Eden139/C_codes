int* addvecteur(int* vect1, int* vect2, size_t taille){
	int* vect = (int*)malloc(taille * sizeof(int));
	for(int i = 0; i < taile; i++){
		*(vect +i) = *(vect1 + i) + *(vect2 + i);
	}
	return vect;
}
void scalaire(int* vect, int scal, size_t taille){
	for(int i = 0; i < taille; i++){
		*(vect +i) = *(vect + i) * taille;
	}
}
int prod_sc(int* vect1, int* vect2, size_t taille){
	int s = 0;
	for(int i = 0; i < taille; i++){
		s += *(vect1 + i) * *(vect2 + i);
	}
	return s;
}
