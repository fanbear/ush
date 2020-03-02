#include "ush.h"

void mx_change_dir(cmd_bl *cmd) {
	DIR *dir;

	if (cmd->argv[0] == NULL)
		mx_ush_loop();
	dir = opendir(cmd->argv[0]);
	if (mx_strcmp(cmd->argv[0], "..") == 0) {
		chdir("..");
		mx_ush_loop();
		char s[1000];
		printf("%s\n", getcwd(s, 1000));
	}
	
    if (!dir) {
        perror("cd"); //  написать свой
        write(2, cmd->argv[0], mx_strlen(cmd->argv[0]));
        mx_ush_loop();
    }
	if (cmd->argv[0] != NULL) {
		chdir(cmd->argv[0]);
		char s[1000];
		printf("%s\n", getcwd(s, 1000));
		mx_ush_loop();
	}
} 

// mx_del_extra_spaces(cmd->argv[0])
