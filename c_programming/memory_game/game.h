#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
  char s;
  int con;
}Controller;

void startGameLevel();
void createTheSymbols(int c, int l);
void cleanTheScreen();
void game(char **mgame, char **mprint, int c, int l);
void printScreen(char **mprint, int c, int l);
int createGame(int level);
int didIWin(char **mprint, int c, int l);
void help();
