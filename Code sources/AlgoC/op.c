#include <stdio.h>

int main() {
	int a = 7, b = 3, c = 2;
//	b = ++a ;
	printf("a = %d \tb = %d\n", a, b);
	
	a=7; b=3;
//	b = a++;
	printf("a = %d \tb = %d\n", a, b);
	
	printf("a-b-c= %d\t a-(b-c)= %d\n", a-b-c, a-(b-c));
	
	printf("a/b/c= %d\t a/(b/c)= %d", a/b/c, a/(b/c));
	return 0;
}
