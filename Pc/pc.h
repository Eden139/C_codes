#ifndef _PCMIT_H
#define _PCMIT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char mac[40];
	char ethiquette[40];
	char marque[40];
}Pc;
int comparaison(const void *a, const void *b);
int getInfo(char* pathToFile, Pc *mit);
void writeInfo(char* file, Pc *mit, size_t len);
void printInfo(Pc *mit, size_t len);


#endif
