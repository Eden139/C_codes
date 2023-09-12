#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Fonction utilisé pour avoir le choix de l'utilisateur
int Choix(int choix);

/// Compression des fichiers
char** getNbrCopie(int nbrFich,int longueur,char** file, char* arch);
void compressfile(char** file, char* arch);

/// Entrée des caractéristiques et envoi
void entrer_crtsq(char* user, char* passwd, char* ip);
void nouvel_utilisateur(char* passwd, char* user, char* ip);
void utilisateur_actuel(char* user, char* ip, char* passwd, char* arch);
void transfert_de_fichiers(char* user);

/// Décompression des fichiers
void decompression(char *fichier,char *dossier,char *cree_dossier,char *decomp1,char *decomp2);

int main() {

	/* Variable utilisé pour le choix de l'utilisateur */
	int choix = -1;

	/* Variables utilisées pour la compression */
	char** file = NULL;
	int nbrFich = 0;                         ///nombre de fichier
	int longueur = 10;                       ///longueur du fichier
	char arch[100];

	/* Variables utilisées pour les informations de l'autre machine */
	char user[63];		// Le nom de l'utilisateur dans la machine distant
	char passwd[63];	// le mot de passe
	char ip[15];		// l'adresse IP de la machine distant


	/* Variables utilisées pour la décompression */
	char fichier[256];				//fichier .tar.gz
	char dossier[256];				//dossier pour contenir ke fichier decompressé
	char cree_dossier[50]="mkdir ";	// utilisé pour la création du dossier
		/* Utilisés pour : */
	char decomp1[256]="tar xzf ";	//	decompressé le fichier et le
	char decomp2[1000];				//	deplacé vers le dossier

	/* Le choix de l'utilisateur */
	choix = Choix(choix);


	/* Introduction du groupe */


	/* Compression des fichiers */
	if(choix == 0){
		getNbrCopie(nbrFich, longueur, file, arch);  ///allouer l' emplacement du fichier et saisi des ficiers à copier dans un  repertoire
		compressfile(file, arch);          			 ///fonction pour la compression  des fichiers dans un repertoire 
	}
	/* Decompression des fichiers */
	if(choix == 1){
		decompression(fichier,dossier,cree_dossier,decomp1,decomp2);
	}
	/* Entrer les caractéristiques de l'autre machine */
	entrer_crtsq(user, passwd, ip);

	/* si utiliser l'utilisateur actuel */
	utilisateur_actuel(user, ip, passwd, arch);

	/* si créer un nouvel utilisateur */
//	nouvel_utilisateur(passwd, user, ip);

	return 0;
}
/// Le choix de l'utilisateur
int Choix(int choix){
	system("clear");

	printf("Bienvenu dans système de transfert de fichier le plus rapide du monde\n\n");
	while (choix != 0 && choix != 1) {
		printf("\n");
		if (scanf("%d", &choix) != 1) {  	// Vérifier que l'utilisateur entre un nombre
			choix = -1; 			// Réinitialiser le choix pour que l'utilisateur
			while (getchar() != '\n')	// Vider le buffer d'entrée pour éviter une boucle infinie
				printf("Vous ne pouvez entrer que 0 ou 1, réessayer : \n");
		}
		else if (choix != 0 && choix != 1) {
        printf("Vous n'avez que 2 choix 0 ou 1, réessayez : \n");
		}
	}
	return choix;
}
/// Fonction pour avoir les caractéristiques
void entrer_crtsq(char* user, char* passwd, char* ip){
	char choix = 'n';
	while(choix != 'o' || choix != 'O' || choix != 'y' || choix != 'Y'){
	 if(choix == 'n' || choix == 'N'){
		printf("Entrer le nom d'utilisateur  : ");
		scanf("%s", user);

		printf("Entrer le mot de passe : ");
		scanf("%s", passwd);

		printf("Entrer l'IP du serveur : ");
		scanf("%s", ip);

		printf("Ces informations sont-elles correctes[o/n] : ");
		scanf("%s", &choix);
	 }
	 else break;
	}
}

/// Si l'utilisateur est l'utilisateur actuel
void utilisateur_actuel(char* user, char* ip, char* passwd, char* arch){
	char commande[400];
	char creation[100];
	char copie[100];

	/* Écriture dans du mot de passe dans le fichier */
	FILE *fichier = fopen("mot_de_passe777.txt", "w");
		fprintf(fichier,"%s", passwd);
	fclose(fichier);

	/* Copie du fichier contenant le mot_de_passe */
	sprintf(copie, "sshpass -p \"%s\" scp -o StrictHostKeyChecking=yes ~/mot_de_passe777.txt %s@%s:~/ ", passwd, user, ip);
	system(copie);

	/* Création du dossier contenant */
	sprintf(creation, "sshpass -p \"%s\" ssh -o StrictHostKeyChecking=yes %s@%s \"mkdir ~/Backup 2> /dev/null\"", passwd, user, ip);
	system(creation);

	sprintf(commande,"sshpass -p \"%s\" scp -o StrictHostKeyChecking=yes ~/%s.tar.gz %s@%s:~/Backup/ < mot_de_passe777.txt", passwd, arch, user, ip);

	system(commande);

	printf("\n\tTravail terminé, à ma prochaine execution !");

}

/// Si on veut un nouvel utilisateur
void nouvel_utilisateur(char* passwd, char* user, char* ip){

	char cmduser[100];		// la commande qui permet d'ajouter l' utilisateur
	char commande[400];			// la commande qui permet d'entrer dans la machine distant
	char copieTemporaire[100];	// La commande qui copie le fichier temporaire

	/* le nom du nouvel utilisateur */
	char name[64];
	printf("Entrez le nom du nouvel utilisateur : ");
	scanf("%s", name);

	/* Le mot de passe du nouvel utilisateur */
	char password[64];
	printf("entrez le mot de passe du nouvel utilisateur : ");
	scanf("%s", password);

	/* Écriture du fichier temporaire */
	FILE *fichier = fopen("Temporarfile.txt", "w");
	fprintf(fichier, "%s\n%s\n%s\n\n\n\n\n\nyes\n", passwd, password, password);
	fclose(fichier);

 	sprintf(cmduser, "sudo -S adduser %s ", name);

 	// Copie le fichier Temporaire dans la mahine distante
 	sprintf(copieTemporaire, "scp ~/Temporarfile.txt %s@%s:~/ ", user, passwd);
 	system(copieTemporaire);

	sprintf(commande, "sshpass -p \"%s\"ssh %s@%s \"%s < Temporarfile.txt ; rm Temporarfile.txt\"", passwd, user, ip, cmduser);

	printf("%s\n", commande);
	system(commande);
}
//void transfert_de_fichiers(char* name){

//	system();
//}


char** getNbrCopie(int nbrFich,int longueur,char** file, char* arch){

	char creer[50];	// Création du repertoire
	char cmd[90];	// Commande qui permet de copier les fichers dans le repertoire

	/* Saisir le nombre de fichiers */
	printf("entrer le nombre de fichier : ");
	scanf("%d", &nbrFich);

	/* Allocation */
	file = (char**)malloc(nbrFich * sizeof(char*));
	for(int i = 0; i < longueur; i++){
		*(file + i) = (char*)malloc(longueur * sizeof(char));
	}

	/* Création du répertoire */
	printf("Entrez le nom de l'archive de sauvegarde : ");
	scanf("%s", arch);

	sprintf(creer,"mkdir ~/%s  2> /dev/null", arch);
	system(creer);


	printf("Entrez les noms du fichier à sauvegarder: \n");
	for(int i = 0; i < nbrFich; i++){
		printf("%d : ", i+1);                            ///saisi des fichiers à sauvegarder
		scanf("%s", file[i]);
		sprintf(cmd, "find ~/ -name %s -exec cp -r {} ~/%s/ 2> /dev/null \\;", file[i], arch);
		system(cmd);                                  ///commande pour copier les fichiers dans un repertpoire
	}

	return file;
}
/// Fonction pour la compression des fichiers
void compressfile(char** file, char* arch){
	char cmd[200];
	sprintf(cmd,"tar -czvf ~/%s.tar.gz ~/%s 2> /dev/null; rm -r ~/%s", arch, arch, arch);
	system(cmd);	 ///commande pour l' execution du compression
}

/// Fonction utilisé pour la décompression du fichier
void decompression(char *fichier,char *dossier,char *cree_dossier,char *decomp1,char *decomp2){
	printf("Entrez le nom du fichier a recuperer\n");
	scanf("%s",fichier);

	printf("Dossier de recuperation\n");
	scanf("%s",dossier);

	strcat(cree_dossier,dossier);
	system(cree_dossier);

	sprintf(decomp2,"%s -C %s",fichier,dossier);
	strcat(decomp1,decomp2);

	system(decomp1);
}
