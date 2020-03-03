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
	struct stat st;

	lstat(str, &st);
	if (S_ISLNK(st.st_mode))
		return 10;
	if (!S_ISDIR(st.st_mode) && !S_ISREG(st.st_mode))  // если не папка или не существует
		return 0;
	if (S_ISREG(st.st_mode)) // если не файл или несуществует
		return 5;
	
    return 1;
}

static void cd_error(char *str, char *file_name) {
	write(2, str, mx_strlen(str));
	write(2, file_name ,mx_strlen(file_name));
	write(2, "\n", 1);
	mx_ush_loop();
}

void mx_change_dir(cmd_bl *cmd) {
	if (cmd->argv[0] == NULL || !cmd->argv[0]) {
		chdir(cmd->home);
		mx_ush_loop();
	}																					//если просто cd
	else { 																				//если есть хоть один аргумент
		if (check_flag(cmd) == 1) 														//если есть флаг
			printf("flag have");		
    	else { 																			//если флага нет
    		if (!is_dir(cmd->argv[0])) 													// проверка что агрумент это папка
    			cd_error(NO_F_OR_D, cmd->argv[0]);

    		else if (is_dir(cmd->argv[0]) == 5) 										//если это файл
    			cd_error(NO_D, cmd->argv[0]);
    		else if (is_dir(cmd->argv[0]) == 10)
    			printf("link\n");
    		else if (mx_strcmp(cmd->argv[0], "..") == 0) {
    			chdir("..");
				mx_ush_loop();
    		}
    		else if (mx_strcmp(cmd->argv[0], "../") == 0) { 								//возврат на уровень выше
				chdir("../");
				mx_ush_loop();
			}
			else if ((is_dir(cmd->argv[0]) || is_dir(cmd->argv[1])) && !cmd->argv[2]) // если два аргумента папки
				cd_error(STR_NO_PWD, cmd->argv[0]);
			else if (cmd->argv[0] && cmd->argv[1] && cmd->argv[2]) {
				write(2, MANY_ARGV, 22);
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

