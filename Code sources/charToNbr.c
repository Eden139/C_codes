#include <stdio.h>
#include <stdlib.h>
#define delimiteur ','

int* date(char* caractere);
double charToDouble(char* caractere);
int testDelim(char* caractere, char delim);
unsigned trouveColonne(char* caractere, char delim);
unsigned trouveLigne(char* caractere, char delim);
int compareNombre(int n, int m);
char** separer(char* caractere, char delim);
char** allocation2D(char** caractere, unsigned ligne, unsigned colonne);
int charToInt(char* atransf);
int manisa(char* caractere);
double puiss(double nombre, int puissance);
int* placeDelim(char* caractere, char delim);
int* month(double annee);
double absolu(double nombre);
char* intToCharEt(int nombre);
int manisaInt(int nombre);
char uniteToChar(int nombre);
char* fotoana(int* nombre);

int main() {
	char *nombre = (char*)malloc(10 * sizeof(char));
	int *number = date("21,22/12,6/2006");

	nombre = fotoana(number);
	printf("%s\n", nombre);


	return 0;
}
char* fotoana(int *nombre){
	char *fotoana = (char*)malloc(100 * sizeof(char));
	for(int i = 0, k = 0,l = 2 ; i <= 6 ; i += 3){
		for(int j = i , m = 0; j <= i + manisaInt(*(nombre + k))  ; j++){
			*(fotoana + j) = *(intToCharEt(*(nombre + k)) + m);
			m++;
		}
		*(fotoana + l)= '/';
		k++;
		l = i + 2;
	}
	*(fotoana + 10) = ' ';

	for(int i = 11, k = 3,l = 13 ; i <= 17 ; i += 3){
		for(int j = i , m = 0; j <= i + manisaInt(*(nombre + k))  ; j++){
			if(*(nombre + k) < 10){
				*(fotoana + j) = '0';
				*(fotoana + j + 1) = *(intToCharEt(*(nombre + k)) + m);
				
			}
			else{
				*(fotoana + j) = *(intToCharEt(*(nombre + k)) + m);
			}
			m++;
		}
		*(fotoana + l)= ':';
		k++;
		l = i + 2;
	}

	return fotoana;
}
char* intToCharEt(int nombre){
	double isa = 0;
	int n = manisaInt(nombre);
	char* caractere = (char*)malloc(100);
	
	isa = (puiss(10, -n) * nombre); 	

	for(int i = 0; i <= n ; i++){
		*(caractere + i) = uniteToChar((int)(isa + 0.00000000001));
//		if(i == n - 1 && isa - (int)isa >= 0.00001){
//			*(caractere + n) = '0';
//			break;
//		}
		isa = (isa - (int)isa) * 10;      

	}
	return caractere;
}
int manisaInt(int nombre){
	int n = 0; 	// Le compteur
	while(nombre / (int)puiss(10, n) > 9){
		n++;
	}
	return n;
}
char uniteToChar(int nombre){
	char *caractere = (char*)malloc(10 * sizeof(int));
	caractere = "0123456789";
	return *(caractere + nombre);
}

int* date(char* caractere){

	int *date = (int*)malloc(7 * sizeof(int));

	double n = 0;
	double eps = puiss(10, -12);

	double jour = charToDouble(*(separer(caractere, '/') + 0));
	double mois = charToDouble(*(separer(caractere, '/') + 1));
	double annee = charToDouble(*(separer(caractere, '/') + 2));
	
	double heure = 0.0;
	double minute = 0.0;
	double seconde = 0.0;

	int *volana = (int*)malloc(13 * sizeof(int));
	volana = month(annee);
			
	for(int i = 1 ; i <= 2 ; i++){
		if(absolu(annee - (int)annee) >= eps){
			if(annee >= 0){
				n = absolu(annee - (int)annee);
				n = 12 * n;
				mois = mois + n;
				annee = (int)annee + 0.0;	
			}
			else{
				n = 1 - absolu(annee - (int)annee);
				n = 12 * n;
				mois = mois + n;
				annee = (int)annee - 1.0;
			}
			n = 0;
		}
		if(mois < 0 || absolu(mois - (int)mois) >= eps){
			n = absolu(mois / 12);
			mois = mois + 12 * ((int)n + 1) + 1;
			annee = annee - (int)n - 1;
		}
		if(mois > 12 ){
			n = mois / 12;
			annee = annee + (int)n;
			mois = mois - 12 * (int)n;
			n = 0;
		}
		
		if((mois - (int)mois) >= eps){
			n = mois - (int)mois;
			jour = jour + (n * (*(volana + ((int)mois - 1))));
			mois = (int)mois + 0.0;
		}

		if(jour > 365){
			if((int)annee % 4 == 0)
				n = jour / 366;
			else
				n = jour / 365;
			annee = annee + (int)n;
			jour = jour - (int)n * 365;
			n = 0.0;	
		}
		if(jour <= 0){
			n = absolu(jour / (*(volana + (int)mois - 1)));
			int j = (int)mois - 2;
			while(jour < 0){
				if(j <= 0){
					j = 11;
				}
				jour = jour + *(volana + j);	
				j--;
			} 
			jour = jour + 1;
			mois = mois - (int)n - 1;
		}
		if(jour > *(volana + (int)mois - 1)){
			n = jour / (*(volana + (int)mois - 1));

			for(int i = (int)mois - 1 , j = i ; i <= (int)mois + (int)n - 2 ; i++){
				if(j >= 12){
					j = 0;
				}
				jour = jour - *(volana + j);
				j++;
				
			}
			mois = mois + (int)n;
		}
		n = jour - (int)jour;
	}
	*(date + 0) = (int)jour;
	*(date + 1) = (int)mois;
	*(date + 2) = (int)annee;

	heure = n * 24;
	*(date + 3) = (int)heure;
	minute = (heure - (int)heure) * 60;
	*(date + 4) = (int)minute;
	seconde = (minute - (int)minute) * 60;
	*(date + 5) = (int)seconde + 1;
	if(*(date + 5) == 60){
		*(date + 4) += 1;
		*(date + 5) = 0;
	}	
	for(int i = 0 ; i <= 5 ; i++){
			printf("%d\n", *(date + i));
	}
	return date;
}
double absolu(double nombre){
	if(nombre < 0){
		nombre = -nombre;	
	}
	return nombre;
}

int* month(double annee){
	int *volana = (int*)malloc(13 * sizeof(int));
	for(int i = 0 ; i < 8 ; i += 2){
		*(volana + i) = 31;
	}
	if((int)annee % 4 == 0)
		*(volana + 1) = 29;
	else
		*(volana + 1) = 28;

	for(int i = 3 ; i < 8 ; i += 2){
		*(volana + i) = 30;
	}
	for(int i = 7 ; i<= 11 ; i += 2){
		*(volana + i) = 31;
	}
	for(int i = 8 ; i<= 12 ; i += 2){
		*(volana + i) = 30;
	}
	return volana;
}
double charToDouble(char* caractere){
	double nombre = 0.0;
	
	char **tab = NULL;

	if(testDelim(caractere, delimiteur) == 0){
		nombre = charToInt(caractere) + 0.0;
		return nombre;
	}

	else{
		tab = allocation2D(tab, trouveLigne(caractere, delimiteur), trouveColonne(caractere, delimiteur));	
		tab = separer(caractere, delimiteur);
		if(charToInt(*tab) >= 0)
			nombre = charToInt(*tab) + (puiss(10, -(manisa(caractere) - *placeDelim(caractere, delimiteur)) + 1) * charToInt(*(tab + 1)));
		else
			nombre = charToInt(*tab) - (puiss(10, -(manisa(caractere) - *placeDelim(caractere, delimiteur)) + 1) * charToInt(*(tab + 1)));
		return nombre;
	}
}
int testDelim(char* caractere, char delim){
	int nombre = 0;
	while(*(caractere + nombre) != '\0'){
		if(*(caractere + nombre) == delim)
			break;
		nombre++;
	}
	if(nombre == manisa(caractere))
		return 0;
	else
		return nombre;
}
unsigned trouveColonne(char* caractere, char delim){
	unsigned max = *placeDelim(caractere, delim);
	short i = 1;
	while(*(placeDelim(caractere, delim) + i) != -1){
		max = compareNombre(max, (*(placeDelim(caractere, delim) + i) - *(placeDelim(caractere, delim) + i - 1)));
		i++;
	}
	max = compareNombre(max, manisa(caractere) - *(placeDelim(caractere, delim) + i - 1));
	return max;
}
unsigned trouveLigne(char* caractere, char delim){
	int n = 0;
	while(*(placeDelim(caractere, delim) + n) != -1){
		n++;	
	}
	n++;
	return n;
}
int compareNombre(int n, int m){
	if(n > m){
		return n;
	}
	else{
		return m;
	}
}

char** separer(char* caractere, char delim){
	char **nombres = NULL;	

     	nombres = allocation2D(nombres, trouveLigne(caractere, delim), trouveColonne(caractere, delim));	

	for(int i = 0, n = 0 , m = 0 ; i <=  manisa(caractere) ; i++){
		*(*(nombres + n) + m) = *(caractere + i);	
		if(i == *(placeDelim(caractere, delim) + n) - 1){
			m = -1;
			i += 1;
			n++;
		}	
		m++;
	}		
	return nombres;
}

char** allocation2D(char** caractere, unsigned ligne, unsigned colonne){
	caractere = (char**)malloc(ligne * sizeof(char*));
	for(unsigned i = 0 ; i < ligne ; i++){
		*(caractere + i) = (char*)malloc(colonne * sizeof(char));
	}
	return caractere;	
}
int charToInt(char* atransf){
	int nombre = 0;
	if(*atransf == '-'){
		for(int i = (manisa(atransf) - 1) ; i >= 1; i--){
			nombre = nombre + (*(atransf + i ) - 48) * (int)puiss(10, manisa(atransf) - (i + 1));
		}
		return -nombre;
	}
	else{
		for(int i = (manisa(atransf) - 1) ; i >= 0 ; i--){
			nombre = nombre + (*(atransf + i) - 48) * (int)puiss(10, manisa(atransf) - (i + 1));
		}
		return nombre;
	}
}
int manisa(char* caractere){
	int i = 0;	
	while(*(caractere + i) != '\0'){
		i++;
	}
	return i;
}
double puiss(double nombre, int puissance){
	double number = nombre;
	int n = 1;
	if(puissance <= 0){
		n = puissance;
		puissance = - puissance;
	}
	if(puissance == 0){
		return 1;
	}
	for(int i = 1 ; i < puissance ; i++){
		nombre = nombre * number ;
	}
	if(n < 0){
		nombre = 1 / nombre ;
	}
	return nombre;

}
int* placeDelim(char* caractere, char delim){
// Initialisation
	int nombre = 0;		// Le compteur pour le caractère
	int n = 0;		// Le compteur pour le tableau d'entiers à retourner
	int* number = malloc(123 * sizeof(int));	// Le tableau d'entiers

// Traitement
	if(*caractere == '\0'){
		*number = 0;
		return number;
	}
	else{	
		while( *(caractere + nombre) != '\0'){
			if(*(caractere + nombre) == delim){
				*(number + n) = nombre;
				n++;
			}
		nombre++;
		}
	*(number + n) = -1;
	return number;
	}
}

