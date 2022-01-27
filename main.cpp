#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include "make.h"
#include "print.h"
#include "save.h"
using namespace std;

int m = 3, n = 9;
int board[9][9];
int playboard[9][9];
int ok_to_play[9][9];

bool search(int c = 0){     // generate the sudoku board
    int i = c/9; 
    int j = c%9;
    int num[9] = {1,2,3,4,5,6,7,8,9};
    for (int h=0;h<20;h++) {    // shuffle the num array
        int r1 = rand()%9;
        int r2 = rand()%9;
        int tmp = num[r1];
        num[r1] = num[r2];
        num[r2] = tmp;
    }
    for (int h=0;h<9;h++){
        if ( (rowcnt(i, num[h], board)==0) && (colcnt(j, num[h], board)==0) && box_ok(i - i % m,j-j%m,num[h],board)) {      // check if the number satisfy the board requirement
            board[i][j]=num[h];
            if (c+1>=81 || search(c+1)) {
                return 1;
            }
        }
        if (h==8) {
            board[i][j] = 0;
            return 0;
        }
    }
    return 1;
}

bool playok(int play){      // check if play is a valid value
    if(play ==1 || play==2 || play==3)
        return true;
    return false;
}
int main(){
    
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            playboard[i][j] = 0;    // initialize the board
        }
    }
    srand(time(NULL));      // set random seed
    welcome();
    int play;
    startintro();
    cin >> play; // play is the user input for which mode does he/she prefer
    while (!playok(play)){      // check if the command is invalid
        cout << ":,) invalid input please try again "<< endl;
        startintro();
        cin >> play;
    }
    while (play !=3){

        if (play == 1){ // new game
            int lvl;
            for (int i=0;i<9;i++){ // initalise the board into 0's
                for (int j=0;j<9;j++){
                    board[i][j] = 0;
                }
            }
            search(); // generate the board
            playintro();
            cin >> lvl;
            for (int i=0;i<9;i++){
                for (int j=0;j<9;j++){
                    playboard[i][j]= board[i][j]; // making the playboard = board
                    ok_to_play[i][j] = 0; // not available to play
                }
            }

            for (int i=0;i<=(3*lvl);i++){
                for (int j=0;j<=(3*lvl);j++){
                    int row = rand()%9;
                    int col = rand()%9;
                    playboard[row][col] = 0; // generating empty spot for player to input
                    ok_to_play[row][col] = 1; // set the same loc as 1 making the loca availble to change
                }
            }
            startplaying(playboard,board,ok_to_play); // play the board
            cin >> play;
        } else if ( play == 2){
            if (ReadBoard(board)){ // check if board exists in the directory
                ReadPBoard(playboard);
                ReadOBoard(ok_to_play);
                startplaying(playboard,board,ok_to_play);
            }
            else
                startintro();
            cin >> play;
        }
        if (!playok(play)) {        // check if the command is invalid
            cout << ":,) invalid input please try again "<< endl;
            startintro();
            cin >> play;
        }
    }

    return 0;
}

