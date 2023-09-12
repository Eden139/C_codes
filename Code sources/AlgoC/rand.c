#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	printf("Un programme qui génere 10 nombres pseudo aléatoires\n");
	srand(1);
	for(int i=0; i<10; i++)
		printf("%d\n", rand() )

	return 0;
}
