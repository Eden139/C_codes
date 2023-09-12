#include <stdio.h>
#include <string.h>
char itoascii (int i);
int main(){
/*
	char mincharactere (int c){
		return 'a' + c;
	}	
	char majcharactere (int C){
		return 'a' + C;
	}
*/

	printf("Affichage des codes ascii des caractères décimaux\n");
	for (int i = 0; i<=9; i++){
		printf("%c = %d ", itoascii(i), itoascii(i));
	}
	return 0;
}
char itoascii (int i){
	return '0' + i;
}
