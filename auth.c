#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	printf("Content-type: text/html\n\n");
	printf("<!DOCTYPE html>"
			"<html>"
				"<head>"
					"<meta charset=\"utf-8\">"
					"<title>Le site web de la mort</title>"
					"<style>"
						"body {"
							"background-image: url('index2.jpg');"
						"}"
						".table {"
							"border-collapse: collapse;"
							"min-width: 750px;"
							"width: auto;"
							"border: 2px solid dodgerblue;"
							"margin: 100px auto;"
							"cursor: pointer;"
							"box-shadow: 0px 5px 50px rgba(0,0,0,0.15);"
						"}"
						"th {"
							"font-size: 17px;"
						"}"
						"thead tr {"
							"color: #fff;"
							"background: linear-gradient(80deg, dodgerblue, royalblue);"
						"}"
						"th, td {"
							"padding: 15px 20px;"
						"}"
						"tbody, th, td, tr {"
							"border: 1px solid #ddd;"
							"text-align: center;"
						"}"
						"thead th{"
							"font-size: 19px;"
						"}"
					"</style>"
				"</head>"
				"<body style=\"font-family: Sans-serif\">"
					"<table class=\"table\">"
					"<thead>"
						"<tr>"
							"<th>USER</th>"
							"<th>SESSION</th>"
							"<th>SESSION_STATUS</th>"
							"<th>TIME</th>"
						"</tr>"
					"</thead>"
					"<tbody>"
	      );
	
	FILE* auth = fopen("/var/log/auth.log", "r");
	if(auth == NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	char *user, *time, *session, *session_name, *row, *open, *close;
	int line_count = 0;
	while(fscanf(auth, "%*[^\n]\n") != EOF)
		line_count++;
	rewind(auth);

	while(fscanf(auth, "%m[^\n]\n", &row) != EOF) {
		sscanf(row, "%m[^+]", &time);
		if((open = strstr(row, "session opened for user ")) != NULL ||
		   (close = strstr(row, "session closed for user ")) != NULL) {
			sscanf(strstr(row, "pam_unix") + 9, "%m[^:]", &session_name);
			if(open != NULL) {
				sscanf(open + 24, "%m[a-zA-Z0-9]", &user);
				sscanf("opened", "%ms", &session);
			}
			if(close != NULL) {
				sscanf(close + 24, "%m[a-zA-Z0-9]", &user);
				sscanf("closed", "%ms", &session);
			}
			printf("<tr><th>%s</th><td>%s</td><td>%s</td><td>%s</td></tr>", user, session_name, session, time);
		}
	}


	printf("</tbody></table></body></html>");


	return 0;
}
