#include "ush.h"

void mx_chage_dir_and_pwd(char *str) {
	char *s = NULL;

	setenv("OLDPWD", getenv("PWD"), 1);
    chdir(str);
	setenv("PWD", getcwd(s, 1000), 1);
	free(s);
	mx_ush_loop();
}
