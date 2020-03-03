#include "ush.h"

int mx_print_pwd(cmd_bl *cmd) {
	char s[1000];

	if (!cmd->cmd)
		exit(1);
	printf("%s\n", getcwd(s, 1000));
	return 0;
}
