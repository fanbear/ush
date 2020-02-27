#include "ush.h"

void mx_ush_loop (void) {
	g_line *g_line = malloc(sizeof(g_line));

	mx_printstr("ush:> ");
	char s[100];
	g_line->line = mx_ush_read_line(); //чтение аргументов

	g_line->args = mx_split_argv(g_line->line); //разбиваем строку на аргументы
	
	g_line->status = 1; // статус работы цикла
	
	while (g_line->status) {
		printf("%s\n", getcwd(s, 100));
		chdir("/Users/mac/Desktop/ush/src");
		printf("%s\n", getcwd(s, 100));
		mx_launch_process(g_line->args);
		if (mx_launch_process(g_line->args) == 1)
			mx_printstr("Создан дочерний процес");
		exit(1);
	}
}
