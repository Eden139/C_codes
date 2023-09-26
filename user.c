#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
     printf("Content-type: text/html\n\n");

     printf("<html>"
                     "<head>"
                         "<meta charset=\"utf-8\">"
                         "<title>Liste des différents utilisateurs</title>"
			 "<style>table{border-collapse: collapse; boreder-spacing: 0px;}table, th, td{padding: 5px;border: 1px solid}</style>"
                     "</head>"
                     "<body>"
            );
     printf("<table>");
     printf("<thead>"
               "<tr>"
                    "<th>User</th><th>Login</th>"
               "</tr>"
            "</thead>"
           );

     FILE* info_users = fopen("/etc/passwd", "r");
     if(info_users == NULL){
             perror("Votre fichier ne s'ouvre pas");
             exit(EXIT_FAILURE);
     }

     char row[1001], *login;
     int uid;
     while(fgets(row, 1001, info_users) != NULL) {
	for(char *t = strtok(row, ":"), i = 0; t != NULL; t = strtok(NULL, ":"), i++){
		if(i == 0) sscanf(t, "%ms", &login);
		if(i == 2) uid = atoi(t);
		if(i == 5 && uid > 999 && uid < 60001) printf("<tr><th>%s</th><td>%s</td></tr>", login, t);
		if(i == 5) break;
	}
     }

     printf("</table></body></html>");

     return 0;
}

