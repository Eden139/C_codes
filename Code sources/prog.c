#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

/// Entrée des données
	int  n=1;				// Le choix de la personne
	char t[9]="kill -9 ";	// La commande et l'option
	char t2[5];				// Le processus à tuer

	char package[40]="Package : "			; char p[40];	// Le nom du package
	char version[40]="Version : "			; char v[40];	// La version du fichier
	char section[49]="Section : "			; char s[40];	// La section
	char priorite[40]="Priority : "			; char pr[40];	// La priorité
	char architecture[40]="Architecture : "	; char a[40];	// L'architecture des processeurs compatibles
	char dependance[40]="Dependance : "		; char d[40];	// La dépendance des fichiers
	char nomemail[40]="Maintainer : "		; char ne[40];	// Le nom et l'email des créateurs
	char description[40]="Description : "	; char desc[900];//  La description du package
	char homepage[40]="Homepage : "			; char h[40];	// Le page web du créateur
	
	printf("Ce programme permet d'utiliser plsus rapidement les commandes\n");
	while(n!=0){
		printf("Que voulez-vous faire ? \n");

/// Traitement

		printf("[1]-Modifier le fichier passwd avec nano\n[2]-Afficher les processus courants\n[3]-Arrêter un processus\n");
		printf("[4]-Créer un paquet .deb dans votre répertoire personnel\n[0]-Sortir\n");
		printf("Le numéro : ");
		scanf("%d", &n);
		if(n==1){
			system("sudo nano /etc/passwd");
		}
		if(n==2){
			system("ps aux");
		}
		if(n==3){
			system("ps u");
			printf("Quel est le PID du processus ? ");
			printf("----- ");
			scanf("%s", t2);
			strcat(t, t2);
			system(t);
		}
		if(n==4){
			system("mkdir -p Temporar/DEBIAN Temporar/usr/bin Temporar/usr/share/applications/ Temporar/usr/share/icons");
		
			printf("Le nom du package à créer : ");
			scanf("%s", p);
			strcat(package, p);
			
			printf("La version du package 	  : ");
			scanf("%s", v);
			strcat(version, v);
			
			printf("La section 		  : ");
			scanf("%s", s);
			strcat(section, s);
			
			printf("La priorité 		  : ");
			scanf("%s", pr);
			strcat(priorite, pr);
			
			printf("L'architecture des processeurs compatibles : ");
			scanf("%s", a);
			strcat(architecture, a);
			
			printf("Les dépendances du fichier : ");
			scanf("%s", d);
			strcat(dependance, d);
			
			printf("Le nom et l'email du createur(de la forme Nom<nomemail>) : ");
			scanf("%s", ne);
			strcat(nomemail, ne);

			printf("La description du package : ");
			scanf("%s", desc);
			strcat(description, desc);
			
			printf("Le page web du créateur : ");
			scanf("%s", h);
			strcat(homepage, h);
			
			FILE * fp = fopen("control", "w");
			
			fprintf( fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , package, version, section, priorite, architecture, dependance, nomemail, description, homepage);
			
			fclose(fp);

		}
		if(n==0){
			system("exit");
		}
	}
	printf("Fin de ce programme\n");
	return 0;
}
