#include <stdio.h>
#include <stdlib.h>

char tictac[3][3];
int data_P1[10];
int data_P2[8];
int P1_datacontrol = 0;
int P2_datacontrol = 0;
// int X=1;
void initialize();
void storedata();
void Print(int m, int n, char c);
// void arrayinput();
void print();
void combinations(char XO);

void initialize() {
  int i, j;
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) {
      tictac[i][j] = ' ';
    }
    // printf("\n");
  }
}
void storedata() {
  printf("Enter your move in coordinates like 11,22...\n");
  printf("Note:Enter player 1's first move followed by a space\n");
  int i;
  char c;
  for (i = 1; i <= 9; i++) {
    if (i % 2 == 1) {
      printf("Make your move_PX\n");
      c = getchar();
      c = getchar();
      data_P1[P1_datacontrol] = c - 48;
      P1_datacontrol++;
      c = getchar();
      data_P1[P1_datacontrol] = c - 48;
      // printf("isd\n",data Pl[P1 datacontrol]);
      P1_datacontrol++;
      // tictac[][]
      Print(data_P1[P1_datacontrol - 2], data_P1[P1_datacontrol - 1], 'X');
      combinations('X');
    } else {
      printf("What's your move_PO\n");
      c = getchar();
      c = getchar();
      data_P2[P2_datacontrol] = c - 48;
      // printf("Tsd\n",data P2[P2 datacontrol]);
      P2_datacontrol++;
      c = getchar();
      data_P2[P2_datacontrol] = c - 48;
      // printfriod\n",
      // data_P2[P2_datacontrol]);
      P2_datacontrol++;
      Print(data_P2[P2_datacontrol - 2], data_P2[P2_datacontrol - 1], 'O');
      combinations(
          'O'); // printf("%d%d\n",data_P2[P2_datacontrol-2],data_P2[P2_datacontrol-1]);
    }
  }
}

void Print(int m, int n, char c) {
  int i, j;
  tictac[m][n] = c;
  printf("******************\n");
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) {
      printf("%c\t", tictac[i][j]);
    }
    printf("\n");
  }
  printf("******************\n");
}
void combinations(char XO) {
  int combi[8][3] = {{11, 12, 13}, {21, 22, 23}, {31, 32, 33}, {11, 21, 31},
                     {12, 22, 32}, {13, 23, 33}, {11, 22, 33}, {13, 22, 31}};
  int i, j, m, n, flag = 0;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 3; j++) {
      m = combi[i][j] / 10;
      n = combi[i][j] % 10;
      if (tictac[m][n] == XO) {
        flag++;
      }
    }
    if (flag == 3) {
      printf("Player %c won\n", XO);
      exit(0);
    }
    flag = 0;
  }
}

int main() {
  initialize();
  storedata();
  printf("Game Draw\n");
}
