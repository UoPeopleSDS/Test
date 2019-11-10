#include "game.h"
#include <stdlib.h>



void startGameLevel(){
  int level;
  do{
    printf("\n\n=======================\n");
    printf("Memory game version 0.1\n");
    printf("=======================\n");
    printf("Choose your option:\n");
    printf("\t 1 - Easy\n\t 2 - Normal\n\t 3 - Hard\n\t 0 - Help\n");
    printf("=======================\n");
    scanf("%d",&level);

  }while(createGame(level)>0);
}

int createGame(int level){
  switch (level){
    case 1: createTheSymbols(3, 4); level = -1; break;
    case 2: createTheSymbols(5, 6); level = -1; break;
    case 3: createTheSymbols(5, 8); level = -1; break;
    case 0: help(); level = 1; break;
    default:{
      printf("Please choose a valid option\n"); return -1;
    }
  }
  return level;
}

void help(){
  char key;
  cleanTheScreen();
  printf("============================\n");
  printf("             Help           \n");
  printf("============================\n");
  printf("The Easy difficult, has a matriz of 4x5 with 10 different symbols\n");
  printf("The Normal difficult has a matriz of 5x6 with 15 different symbols\n");
  printf("The Hard difficult has a matrix of 5x8 with 20 different symbols\n");
  printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
  printf("How to play:\n");
  printf("\n Type the first number from axis Y + \"Space\" + second one from the axis Y and \"Enter\"\n");
  printf(" Once you have matched all cards, you won!");
}

void createTheSymbols(int c, int l){
  char **mprint = (char**)malloc(c*sizeof(char*));
  char **mgame = (char**)calloc(c,sizeof(char*));
  int size = (c * l);
  int i = 0, j = size-1, k=0;
  srand(time(0));
  Controller *symbols = (Controller*)malloc(size*sizeof(Controller));

  for(char a ='A'; i<(size/2); i++, j--){
    symbols[i].s = a;
    symbols[i].con = 0;
    symbols[j].s = a;
    symbols[j].con = 0;
    a++;
  }

  for(i = 0; i<c; i++){
    mprint[i] = (char*)malloc(l * sizeof(char));
    for(j=0; j<l;j++)
      mprint[i][j] = '?';
  }

  for(i = 0; i<c; i++){
    mgame[i] = (char*)calloc(l, sizeof(char));
  }
  i = 0;
  for(i=0; i<c; i++){
    for(j=0;j<l;j++){
      while(1){
        k = rand()%size;
        if(symbols[k].con<1){
          mgame[i][j] = symbols[k].s;
          symbols[k].con +=1;
          break;
        }
      }
    }
  }

  game(mgame, mprint, c, l);

  free(symbols);
  for(i = 0; i<c; i++){
    free(mprint[i]);
    free(mgame[i]);
  }
  free(*mprint);
  free(*mgame);
}

void cleanTheScreen(){
  for(int i=0; i<30; i++){
    printf("\n");
  }
}

void printScreen(char **mprint, int c, int l){
  cleanTheScreen();
  printf("============================\n" );
  printf("Type the position (eg: 1 2)\n" );
  printf("============================\n" );
  for(int i = 0; i < l; i++){
    printf("%d ", i);
  }
  printf("\n");
  printf("xxxxxxxxxxxxxxxxxx\n");

  for(int i = 0; i < c; i++){
    for(int j = 0; j < l; j++){
      printf("%c ",mprint[i][j]);
    }
    printf("|| %d\n", i);
  }
}

/*
Returns true if x and y coordinates are within array
*/
int isValidEntry(int x, int y, int c, int l) {
  if (x < l && y < c && x >= 0 && y >= 0) {
    return 1;
  }
  printf("Please enter a valid x and y entry\n");
  return 0;
}

void game(char **mgame, char **mprint,int c,int l){
  int x0, y0, x1, y1, turns = 0;
  char enter;
  do{
    printScreen(mprint, c, l);
    //card 1
    do {
      scanf("%d",&x0);
      scanf("%d",&y0);
      if (isValidEntry(x0,y0,c,l) == 1) { //check user input
        break;
      } 
    } while (1);
    mprint[y0][x0] = mgame[y0][x0];

    printScreen(mprint, c, l);

    //card 2
    do {
      scanf("%d",&x1);
      scanf("%d",&y1);
      if (isValidEntry(x1,y1,c,l) == 1) { //check user input
        break;
      }
    } while (1);
    mprint[y1][x1] = mgame[y1][x1];

    printScreen(mprint, c, l);
    printf("Press \"Enter\" to continue\n" );
    getchar(); //clear last new line character
    while(getchar() != '\n'); //wait for enter key

    
    if(mprint[y0][x0]!=mprint[y1][x1]){
      mprint[y0][x0] = '?';
      mprint[y1][x1] = '?';
    }
  }while( didIWin(mprint,c,l)==0);
}

int didIWin(char **mprint, int c, int l){
  for(int i = 0; i < c; i++){
    for(int j = 0; j < l; j++){
      if(mprint[i][j]=='?'){
        return 0;
      }
    }
  }
  cleanTheScreen();
  printf("======================================================\n" );
  printf("      |   |  [---]  |   |    \\  /\\  / | |\\ |  ||          \n");
  printf("      |___|  |___|  |___|     \\/  \\/  | | \\|  ||          \n");
  printf("       ___|                                      []          \n");
  printf("======================================================\n");
  return 1;
}
