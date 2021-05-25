//C program written by Mario Okeke

#include <stdio.h>
#include <ctype.h>
#include "board.h"
#include <time.h>

int main() {
    FILE *fp;
    fp = fopen("Othello-results.txt", "a");
    char player1name[10],player2name[10];//character array for player names
    printf("$ Othello\n");
    printf("        *** WELCOME TO OTHELLO! ***\n");
    printf("Enter the name of Player 1 (Black): ");
    fgets(player1name,10,stdin);
    printf("\nEnter the name of Player 2 (White): ");
    fgets(player2name,10,stdin);
    //variables to hold information
    char board[8][8];
    char pos[3];
    time_t t;
    time(&t);
    int x,y;
    int check,counts=64;
    int player1score,player2score;

    //function for initialising the board
    initialise_board(board,player1name,player2name);

    //while the board still has empty spaces
    while(counts>0){
        check=4;//for each check passed, the check minuses 1
        printf("YOUR MOVE B:");
        //while not all checks have passed
        while(check>0){
            check=4;
            fgets(pos,3,stdin);
            pos[0]= toupper(pos[0]);
            if(pos[0]=='A'){
                y=0; check--;
            }
            else if(pos[0]=='B'){
                y=1; check--;
            }
            else if(pos[0]=='C'){
                y=2; check--;
            }
            else if(pos[0]=='D') {
                y=3; check--;
            }
            else if(pos[0]=='E') {
                y=4; check--;
            }
            else if(pos[0]=='F') {
                y=5; check--;
            }
            else if(pos[0]=='G') {
                y=6; check--;
            }
            else if(pos[0]=='H') {
                y=7; check--;
            }


            if(pos[1]=='1'){
                x=0; check--;
            }
            else if(pos[1]=='2'){
                x=1; check--;
            }
            else if(pos[1]=='3'){
                x=2; check--;
            }
            else if(pos[1]=='4') {
                x=3; check--;
            }
            else if(pos[1]=='5') {
                x=4; check--;
            }
            else if(pos[1]=='6') {
                x=5; check--;
            }
            else if(pos[1]=='7') {
                x=6; check--;
            }
            else if(pos[1]=='8') {
                x=7; check--;
            }

            //if the position is empty
            if(board[x][y]==' '){
                check--;
            }

            int n=0;
            //check that the player has at least one opposite disc in either direction
            //right check
            if (board[x][y + 1] == 'W')
                n += 1;
            //left check
            if (board[x][y - 1] == 'W')
                n += 1;
            //up check
            if (board[x - 1][y] == 'W')
                n += 1;
            //down check
            if (board[x + 1][y] == 'W')
                n += 1;
            //DUR check
            if (board[x - 1][y + 1] == 'W')
                n += 1;
            //DUL check
            if (board[x - 1][y - 1] == 'W')
                n += 1;
            //DLR check
            if (board[x + 1][y + 1] == 'W')
                n += 1;
            //DLL check
            if (board[x + 1][y - 1] == 'W')
                n += 1;
            if(n>0){
                check--;
            }
        }
        board[x][y]='B';

        int h,i,j,k,p;
        //this flanks the opponent if possible
        //right check
        for(k=y+1;k<=7;k++){
            //if there is a friendly disc on the other side of the position
            if(board[x][k]=='B'){
                p=0;
                for(i=k-1;i>y;i--){
                    //checks that there are no empty spaces between the same discs for the flank.if there is one p increments
                    if(board[x][i]==' ')
                        p++;
                }
                //if p is less than 1, flank is permitted
                if(p<1){
                    for(i=k-1;i>y;i--)
                        board[x][i]='B';
                }
                break;
            }
        }
        //left check>
        for(k=y-1;k>=0;k--){
            if(board[x][k]=='B'){
                p=0;
                for(i=k+1;i<y;i++){
                    if(board[x][i]==' ')
                        p++;
                }
                if(p<1){
                    for(i=k+1;i<y;i++)
                        board[x][i]='B';
                }
                break;
            }
        }
        //down check
        for(j=x+1;j<=7;j++){
            if(board[j][y]=='B'){
                p=0;
                for(h=j-1;h>x;h--){
                    if(board[h][y]==' ')
                        p++;
                }
                if(p<1){
                    for(h=j-1;h>x;h--)
                        board[h][y]='B';
                }
                break;
            }
        }
        //up check
        for(j=x-1;j>=0;j--){
            if(board[j][y]=='B'){
                p=0;
                for(h=j+1;h<x;h++){
                    if(board[h][y]==' ')
                        p++;
                }
                if(p<1){
                    for(h=j+1;h<x;h++)
                        board[h][y]='B';
                }
                break;
            }
        }
        //DUR check
        j=x;
        for(k=y+1;k<=7;k++){
            j--;
            if(board[j][k]=='B'){
                p=0;
                i = k-1;
                for(h=j+1;h<x;h++){
                    if(board[h][i]==' ')
                        p++;
                    i--;
                }
                if(p<1){
                    i=k-1;
                    for(h=j+1;h<x;h++){
                        board[h][i]='B';
                        i--;
                    }
                }
                break;
            }
        }
        //DUL check
        j=x;
        for(k=y-1;k>=0;k--){
            j--;
            if(board[j][k]=='B'){
                p=0;
                i = k+1;
                for(h=j+1;h<x;h++){
                    if(board[h][i]==' ')
                        p++;
                    i++;
                }
                if(p<1){
                    i=k+1;
                    for(h=j+1;h<x;h++){
                        board[h][i]='B';
                        i++;
                    }
                }
                break;
            }
        }
        //DLR check
        j=x;
        for(k=y+1;k<=7;k++){
            j++;
            if(board[j][k]=='B'){
                p=0;
                i = k-1;
                for(h=j-1;h>x;h--){
                    if(board[h][i]==' ')
                        p++;
                    i--;
                }
                if(p<1){
                    i=k-1;
                    for(h=j-1;h>x;h--){
                        board[h][i]='B';
                        i--;
                    }
                }
                break;
            }
        }
        //DLL check
        j=x;
        for(k=y-1;k>=0;k--){
            j++;
            if(board[j][k]=='B'){
                p=0;
                i = k+1;
                for(h=j-1;h>x;h--){
                    if(board[h][i]==' ')
                        p++;
                    i++;
                }
                if(p<1){
                    i=k+1;
                    for(h=j-1;h>x;h--){
                        board[h][i]='B';
                        i--;
                    }
                }
                break;
            }
        }

        //score count
        player1score=0,player2score=0;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(board[i][j]=='B'){
                    player1score += 1;
                }
                else if(board[i][j]=='W'){
                    player2score += 1;
                }
            }
        }
        //displays board after each play
        display_board(board,player1name,player2name,player1score,player2score);


        //player 2
        check=4;
        printf("YOUR MOVE W:");
        while(check>0){
            check=4;
            fgets(pos,3,stdin);
            pos[0]= toupper(pos[0]);
            if(pos[0]=='A'){
                y=0; check--;
            }
            else if(pos[0]=='B'){
                y=1; check--;
            }
            else if(pos[0]=='C'){
                y=2; check--;
            }
            else if(pos[0]=='D') {
                y=3; check--;
            }
            else if(pos[0]=='E') {
                y=4; check--;
            }
            else if(pos[0]=='F') {
                y=5; check--;
            }
            else if(pos[0]=='G') {
                y=6; check--;
            }
            else if(pos[0]=='H') {
                y=7; check--;
            }


            if(pos[1]=='1'){
                x=0; check--;
            }
            else if(pos[1]=='2'){
                x=1; check--;
            }
            else if(pos[1]=='3'){
                x=2; check--;
            }
            else if(pos[1]=='4') {
                x=3; check--;
            }
            else if(pos[1]=='5') {
                x=4; check--;
            }
            else if(pos[1]=='6') {
                x=5; check--;
            }
            else if(pos[1]=='7') {
                x=6; check--;
            }
            else if(pos[1]=='8') {
                x=7; check--;
            }

            if(board[x][y]==' '){
                check--;
            }

            int n=0;
            //right check
            if (board[x][y + 1] == 'B')
                n += 1;
            //left check
            if (board[x][y - 1] == 'B')
                n += 1;
            //up check
            if (board[x - 1][y] == 'B')
                n += 1;
            //down check
            if (board[x + 1][y] == 'B')
                n += 1;
            //DUR check
            if (board[x - 1][y + 1] == 'B')
                n += 1;
            //DUL check
            if (board[x - 1][y - 1] == 'B')
                n += 1;
            //DLR check
            if (board[x + 1][y + 1] == 'B')
                n += 1;
            //DLL check
            if (board[x + 1][y - 1] == 'B')
                n += 1;
            if(n>0){
                check--;
            }

        }
        board[x][y]='W';

        //right check
        for(k=y+1;k<=7;k++){
            if(board[x][k]=='W'){
                p=0;
                for(i=k-1;i>y;i--){
                    if(board[x][i]==' ')
                        p++;
                }
                if(p<=0){
                    for(i=k-1;i>y;i--)
                        board[x][i]='W';
                }
                break;
            }
        }
        //left check>
        for(k=y-1;k>=0;k--){
            if(board[x][k]=='W'){
                p=0;
                for(i=k+1;i<y;i++){
                    if(board[x][i]==' ')
                        p++;
                }
                if(p<=0){
                    for(i=k+1;i<y;i++)
                        board[x][i]='W';
                }
                break;
            }
        }
        //down check
        for(j=x+1;j<=7;j++){
            if(board[j][y]=='W'){
                p=0;
                for(h=j-1;h>x;h--){
                    if(board[h][y]==' ')
                        p++;
                }
                if(p<=0){
                    for(h=j-1;h>x;h--)
                        board[h][y]='W';
                }
                break;
            }
        }
        //up check
        for(j=x-1;j>=0;j--){
            if(board[j][y]=='W'){
                p=0;
                for(h=j+1;h<x;h++){
                    if(board[h][y]==' ')
                        p++;
                }
                if(p<=0){
                    for(h=j+1;h<x;h++)
                        board[h][y]='W';
                }
                break;
            }
        }
        //DUR check
        j=x;
        for(k=y+1;k<=7;k++){
            j--;
            if(board[j][k]=='W'){
                p=0;
                i = k-1;
                for(h=j+1;h<x;h++){
                    if(board[h][i]==' ')
                        p++;
                    i--;
                }
                if(p<=0){
                    i=k-1;
                    for(h=j+1;h<x;h++){
                        board[h][i]='W';
                        i--;
                    }
                }
                break;
            }
        }
        //DUL check
        j=x;
        for(k=y-1;k>=0;k--){
            j--;
            if(board[j][k]=='W'){
                p=0;
                i = k+1;
                for(h=j+1;h<x;h++){
                    if(board[h][i]==' ')
                        p++;
                    i++;
                }
                if(p<=0){
                    i=k+1;
                    for(h=j+1;h<x;h++){
                        board[h][i]='W';
                        i++;
                    }
                }
                break;
            }
        }
        //DLR check
        j=x;
        for(k=y+1;k<=7;k++){
            j++;
            if(board[j][k]=='W'){
                p=0;
                i = k-1;
                for(h=j-1;h>x;h--){
                    if(board[h][i]==' ')
                        p++;
                    i--;
                }
                if(p<=0){
                    i=k-1;
                    for(h=j-1;h>x;h--){
                        board[h][i]='W';
                        i--;
                    }
                }
                break;
            }
        }
        //DLL check
        j=x;
        for(k=y-1;k>=0;k--){
            j++;
            if(board[j][k]=='W'){
                p=0;
                i = k+1;
                for(h=j-1;h>x;h--){
                    if(board[h][i]==' ')
                        p++;
                    i++;
                }
                if(p<=0){
                    i=k+1;
                    for(h=j-1;h>x;h--){
                        board[h][i]='W';
                        i--;
                    }
                }
                break;
            }
        }

        //score count
        player1score=0,player2score=0;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(board[i][j]=='B'){
                    player1score += 1;
                }
                else if(board[i][j]=='W'){
                    player2score += 1;
                }
            }
        }
        display_board(board,player1name,player2name,player1score,player2score);

        //counts up to ensure the game is not over
        //check empty spaces
        counts=64;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(board[i][j]!=' ')
                    counts--;
            }
        }
    }

    if(player1score>player2score){
        printf("*** PLAYER 1 IS THE WINNER ***\n");
        fprintf(fp, "%-21s%24s",player1name,ctime(&t));
    }
    else if(player2score>player1score){
        printf("*** PLAYER 2 IS THE WINNER ***\n");
        fprintf(fp, "%-21s%24s",player2name,ctime(&t));
    }

    printf("SCORE: %s (BLACK) %d:%d (WHITE) %s\n",player1name,player1score,player2score,player2name);



    return 0;
}
