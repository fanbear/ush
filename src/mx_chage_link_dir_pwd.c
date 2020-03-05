#include "ush.h"

void mx_chage_link_dir_pwd(char *str) {
	char *s = NULL;

	setenv("PWD", str, 1);
    chdir(str);
	free(s);
	mx_ush_loop();
}
