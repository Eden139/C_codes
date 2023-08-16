#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char T[1001];
    scanf("%[^\n]", T);
    for(char *t = strtok(T, " "); t; t = strtok(0, " ")){
        if(!strcmp(t, "nl")){
            putchar(10);
            continue;
        }
        int a = 0; char *b=malloc(4);
        sscanf(t, "%d%s", &a,b);
        if(*b == 0){
            a/=10;
            *b=t[strlen(t)-1];
        }
        for(int i = 0; i < a; i++){
            if(!strcmp(b, "sp"))
                putchar(32);
            else if(!strcmp(b, "bS"))
                putchar(92);
            else if (!strcmp(b, "sQ"))
                putchar(39);
            else printf("%s", b);
        }
        
    }

    return 0;
}
