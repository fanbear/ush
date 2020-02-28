#include "ush.h"

void mx_ush_loop (void) {
	g_line *g_line = malloc(sizeof(g_line));
	int status = 1;
	while (status) {
		mx_printstr("u$h> ");
		g_line->line = mx_ush_read_line(); //чтение аргументов

		g_line->args = mx_split_argv(mx_strtrim(g_line->line)); //разбиваем строку на аргументы






		free(g_line->args);
		free(g_line->line);
		mx_ush_loop();
	}
}
