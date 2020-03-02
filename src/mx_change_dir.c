#include "ush.h"

static int check_flag(cmd_bl *cmd) {
	//если есть хоть один флаг вернуть 1 иначе 0
	for (int i = 0; cmd->argv[i]; i++) {
		if (cmd->argv[i][0] == '-')
			return 1;
	}
	return 0;
}

static int is_dir(char *str) {
	DIR *dir;

	dir = opendir(str);
	if (!dir) {
		return 0;
    }
    return 1;
}


void mx_change_dir(cmd_bl *cmd) {
	if (cmd->argv[0] == NULL || !cmd->argv[0]) //если просто cd
		mx_ush_loop();
	else { //если есть хоть один аргумент
		if (check_flag(cmd) == 1) //если есть флаг
			printf("flag have");		
    	else { //если флага нет
    		if (!is_dir(cmd->argv[0])) { // проверка что агрумент это папка
    			write(2, "cd: no such file or directory: ", 31);
    			write(2, cmd->argv[0] ,mx_strlen(cmd->argv[0]));
    			write(2, "\n", 1);
    			mx_ush_loop();
    		}	
    		else if (mx_strcmp(cmd->argv[0], "..") == 0) { //возврат на уровень выше
				chdir("..");
				mx_ush_loop();
			}
			else if ((is_dir(cmd->argv[0]) || is_dir(cmd->argv[1])) && !cmd->argv[2]) { // если два аргумента папки
				write(2, "cd: string not in pwd: ", 23);
				write(2, cmd->argv[0] ,mx_strlen(cmd->argv[0]));
				write(2, "\n", 1);
				mx_ush_loop();
			}
			else if (cmd->argv[0] && cmd->argv[1] && cmd->argv[2]) {
				write(2, "cd: too many arguments", 22);
				write(2, "\n", 1);
				mx_ush_loop();
			}
			else {
				chdir(cmd->argv[0]);
    			mx_ush_loop();
			}
    	}
	}
} 

