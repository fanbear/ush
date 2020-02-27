#include "ush.h"

void mx_ush_loop (void) {
	g_line *g_line = malloc(sizeof(g_line));

	mx_printstr("ush:> ");
	g_line->line = mx_ush_read_line(); //чтение аргументов
	g_line->status = 1; // статус работы цикла
	while (g_line->status) {
		if (g_line->line != NULL) {
			mx_printstr(g_line->line);
			g_line->status = 0;
		}
	}
}
