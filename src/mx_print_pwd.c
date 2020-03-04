#include "ush.h"

static int check_flag(cmd_bl *cmd) {
	for (int i = 0; cmd->argv[i]; i++) {
		if (mx_strcmp(cmd->argv[0], "-L") == 0)
			return 1;
		if (mx_strcmp(cmd->argv[0], "-P") == 0)
			return 2;
	}
	return 0;
}

static void pwd_error(char *str, cmd_bl *cmd) {
	write(2, str, mx_strlen(str));
	write(2, "\n", 1);
	cmd->exit = 1;
	mx_ush_loop();
}

int mx_print_pwd(cmd_bl *cmd) {
	char s[1000];

	if (getcwd(s, 1000) == 0) {
		cmd->exit = 1;
		printf("%s\n", "error");
	}
	if (cmd->argv[0] == NULL)
		printf("%s\n", getcwd(s, 1000));
	else if (check_flag(cmd) == 0)
		pwd_error("pwd: too many arguments", cmd);
	else if (check_flag(cmd) == 1)
		printf("%s\n", getcwd(s, 1000));
	else if (check_flag(cmd) == 2) 
		printf("link\n");
	return 0;
}
