#include "pc.h"

int main(){
	Pc mit[50];
	int len = 0;
	len = getInfo("info.csv", mit);
	qsort(mit, len, sizeof(Pc), comparaison);
	printInfo(mit, len);
	writeInfo("fileI.csv", mit, len);

	return 0;
}
