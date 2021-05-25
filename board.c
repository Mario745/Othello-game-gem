//
// Created by mario on 23/04/2021.
//
#include <stdio.h>
#include "board.h"

void initialise_board(char board[8][8],char player1name[5],char player2name[5]){
    printf("Score: %s (Black) 2:2 %s (White)\n",player1name,player2name);
    int i;
    //initialise all spots to ' '
    for(i=0;i<8;i++){
        for(int j=0;j<8;j++)
            board[i][j]=' ';
    }
    board[3][3]='W'; board[3][4]='B';
    board[4][3]='B'; board[4][4]='W';
    for(i=0;i<8;i++){
        printf("  --- --- --- --- --- --- --- ---\n");
        printf("%d",i+1);
        printf("| %c | %c | %c | %c | %c | %c | %c | %c |\n",board[i][0],board[i][1],board[i][2],board[i][3],board[i][4],board[i][5],board[i][6],board[i][7]);
    }
    printf("  --- --- --- --- --- --- --- ---\n");
    printf("   A   B   C   D   E   F   G   H \n");
}

void display_board(char board[8][8],char player1name[10], char player2name[10],int player1score,int player2score){
    printf("Score: %s (Black) %d:%d %s (White)\n",player1name,player1score,player2score,player2name);

    int i;
    for(i=0;i<8;i++){
        printf("  --- --- --- --- --- --- --- ---\n");
        printf("%d",i+1);
        printf("| %c | %c | %c | %c | %c | %c | %c | %c |\n",board[i][0],board[i][1],board[i][2],board[i][3],board[i][4],board[i][5],board[i][6],board[i][7]);
    }
    printf("  --- --- --- --- --- --- --- ---\n");
    printf("   A   B   C   D   E   F   G   H \n");
}