#include "ush.h"


static char *what_it_cmd(char *line) {
	char *str[11] = {"exit", "fg", "unset", "export", "cd",
	                "pwd", "echo", "which", "env", NULL};
	char *ch_str =  malloc(sizeof(char) * 20);

	if(!ch_str)
		exit(1);
	for (int i = 0; line[i] != '\n'; i++) {
		if (line[i] == ' ')
			break;
		ch_str[i] = line[i];
	}
	for (int i = 0; str[i]; i++) {
		if (mx_strcmp(ch_str, str[i]) == 0) {
			mx_strdel(&ch_str);
			return str[i];
		}
	}
	mx_strdel(&ch_str);
	return "error";
}

static void add_to_struct(cmd_bl *cmd, char *line) {
	cmd->cmd = what_it_cmd(line);
	char *str = malloc(sizeof(char) * mx_strlen(line) - mx_strlen(cmd->cmd));
	int size = mx_strlen(cmd->cmd);
	int j = 0;

	for(int i = size + 1; line[i]; i++) {
		if (line[i] == '\n')
			i++;
		str[j] = line[i];
		j++;
	}
	cmd->argv = mx_strsplit(str, ' ');
	for (int i = 0; cmd->argv[i]; i++) {
	}
}

void mx_builtin_func(char *line) {
	cmd_bl *cmd = malloc(sizeof(cmd_bl));

	add_to_struct(cmd, line);

	if (mx_strcmp(cmd->cmd, "error") == 0) {
		printf("aasdasdasd\n");
		exit(1); //  если левак
	}
	if (mx_strcmp(cmd->cmd, "exit") == 0)
		exit(0); //  + проверка на аргументы
	if (mx_strcmp(cmd->cmd, "pwd") == 0)
		mx_print_pwd(cmd); // печать pwd
	if (mx_strcmp(cmd->cmd, "cd") == 0)
		mx_change_dir(cmd); // печать pwd
}
