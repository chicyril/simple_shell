#ifndef _H
#define _H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

#define DEFAULT_BUFFSIZE 32

extern char **environ;

int read_cmd(char **cmd_line);
ssize_t get_line(char **buffadr, size_t *buffsz, int fd);
int gl_vauto_init(char **buffadr, size_t *buffsz, int fd);
char *buff_realloc(char *ptr, size_t oldsz, size_t newsz);
char **gettokens(char *str, const char *delim);
char *strtotok(char *str, const char *delim);
int gettok_count(char *str, const char *delim);
char *dup_str(char *str);
char *cat_str(char *s1, char *s2);
char *mvpstr(char *pos, const char *delim);
int chr_count(char *str);
bool isamatch(char *str1, char *str2);
bool chrstr(char c, const char *str);
bool isbiutils(char **cmd_toks);
void print_env(void);
bool isvalid(char *cmd);
bool isvalidpath(char **cmd);
void squash(char **str);
char *geten_var(char *var);
void xxecute(char **cmd);
int sh_exit(char **cmd_toks);
int sh_atoi(char *s);

#endif
