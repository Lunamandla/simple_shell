#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>



int main(int ac, char **av, char **env);
void _prompt(void);
void _handle(int signals);
void _EndOfFile(char *buffer);
void _shell_exit(char **command);



void child_pid(char **order, char *form, char **envir, int loops);
int shift_folder(const char *way);



void Execute(char **command, char *name, char **env, int cicles);
void PrintEnvironment(char **env);
char **GetPath(char **env);
void ErrorMessage(char *name, int cicles, char **command);



char **sstrtok(char *buffer, const char *s);



void FreeMember(char **command);
void ExitFree(char **command);



int _StringCompare(char *s1, char *s2);
unsigned int _StringLength(char *s);
char *_StringCopy(char *dest, char *src);
int _AtoI(char *s);
char *_StringConcatinate(char *dest, char *src);


#endif
