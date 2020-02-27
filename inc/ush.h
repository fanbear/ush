#ifndef ULS_H
#define ULS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <fcntl.h>
#include <malloc/malloc.h>
#include <dirent.h>
#include "libmx/inc/libmx.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/acl.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <grp.h>

#define USH_BUFSIZE 1024
#define LINE_DELIM " \t\r\n\a"


typedef struct get_line {
	char *line;
	char **args;
	int status;

} g_line;



void         mx_ush_loop (void); // базовый цикл
char         *mx_ush_read_line(void); // парсинг вводимых данных
char         **mx_split_argv(char *line); //сплит линии на аргументы
int          mx_launch_process(char **argv);

#endif
