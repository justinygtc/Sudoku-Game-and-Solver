#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "print.h"
#include "save.h"
using namespace std;

bool check(int board[9][9]){    // check the sudoku board is properly filled or not by inputing board and output a boolean
    bool correct = true;    //assume that the board is valid
    for (int i = 0; i < 9; i++) {    //check the horizontal requirement
        bool a[9] = {false,false,false,false,false,false,false,false,false};
        for (int j = 0; j < 9; j++) {
            a[board[i][j]-1] = true;        //record the appearances
        }
        int cnt = 0;
        for (int j = 0; j < 9; j++) {
            if (a[j] == true) {
                cnt += 1;
            }
        }
        if (cnt != 9) {        //check if all numbers are present in the row
            correct = false;
        }
    }
    for (int i = 0; i < 9; i++) {    //check the vertical requirement
        bool a[9] = {false,false,false,false,false,false,false,false,false};
        for (int j = 0; j < 9; j++) {
            a[board[j][i]-1] = true;
        }
        int cnt = 0;
        for (int j = 0; j < 9; j++) {
            if (a[j] == true) {
                cnt += 1;
            }
        }
        if (cnt != 9) {
            correct = false;
        }
    }
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            //loop through each small square
            bool a[9] = {false,false,false,false,false,false,false,false,false};
            for (int ii = 0; ii<3; ii++) {
                for (int ji = 0; ji<3; ji++) {
                    //loop through each block
                    a[board[i*3+ii][j*3+ji]-1] = true;
                }
            }
            int cnt = 0;
            for (int j = 0; j < 9; j++) {
                if (a[j] == true) {
                    cnt += 1;
                }
            }
            if (cnt != 9) {
                correct = false;
            }
        }
    }
    return correct;
}

bool box_ok(int x,int y,int target, int board[9][9]){   // check if the box can contain the number by inputing board and output a boolean
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (board[x+i][y+j]==target)
                return false;
        }
    }
    return true;
}

int rowcnt(int x, int target, int board[9][9]){  // check the whole row have how many that number by inputing board and output a boolean
    int times = 0;
    for (int i = 0; i < 9; i++){
        if (board[x][i] == target)
            times+=1;
    }
    return times;
}

int colcnt(int x, int target, int board[9][9]){  // check the whole col have how many that number by inputing board and output a boolean
    int times = 0;
    for (int i = 0; i < 9; i++){
        if (board[i][x] == target)
            times+=1;
    }
    return times;
}

bool moveok(char move){     // check if the instruction is valid
    if (move == 'D' || move == 'A' || move == 'L' || move == 'H')
        return true;
    return false;
}



void possiblenum(int playboard[9][9], int row, int col) {   // generate possible numbers of a specific block, input the board and the block coordinates
    bool p[9];
    for (int i = 0; i < 9; i++) {
        p[i] = true;
    }
    for (int i = 0; i < 9; i++) {
        p[playboard[row][i]-1] = false;
        p[playboard[i][col]-1] = false;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            p[playboard[row/3*3+i][col/3*3+j]-1] = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
        if (p[i] == true)
            cnt += 1;
    }
    int * printingarray = new int[cnt];     // dynamic array is used for printing
    int pt = 0;
    for (int i = 0; i < 9; i++) {
        if (p[i] == true) {
            printingarray[pt] = i+1;
            pt += 1;
        }
    }
    cout << endl;
    cout << "The possible numbers are: ";
    for (int i = 0; i < cnt; i++) {
        cout << printingarray[i] << " ";
    }
    delete[] printingarray;     // dynamic array is deleted
}


void startplaying(int playboard[9][9],int board[9][9],int ok_to_play[9][9]){       // start the game
    string input;
    input = "play";
    move(); // game commands intro
    char move;
    int row, col, answer;

    while ( input != "end"){
        PrintBoard(playboard,ok_to_play);
        cout << "your move: ";
        cin >> move; // move is the input for player to choose what his/her next move is 
        while (!moveok(move)){
            cout << " :,) INVALID MOVE PLEASE ENTER AGAIN" << endl;
            cout << "your move: ";
            cin >> move;
        }

        if (move == 'L')
            input = "end";
        if (move == 'A' || move == 'D' || move == 'H'){
            cout << "row: ";
            cin >> row;
            cout << "col: ";
            cin >> col;
        }
        if (move == 'H') { // searching availble digits in the input loc
          possiblenum(playboard,row,col);
        }
        if (move =='A'){
            cout << "digit: ";
            cin >> answer;
        }
        if (move == 'A'  && playboard[row][col] == 0 && ok_to_play[row][col] == 1 && answer <10 && answer >0) // check if the  loc n digit are valid
            playboard[row][col] = answer;
        // alrdy an input digit there
        else if (move == 'A' && answer <10 && answer >0 && row <9 && row>=0 && col <9 && col >= 0 && ok_to_play[row][col] == 1) // diff cases diff output
            cout << "this location has been occupied"<< endl << "please try again"<< endl;
        // the loc is fixed
        else if (move == 'A' && ok_to_play[row][col] == 0 && answer <10 && answer >0 && row <9 && row>=0 && col <9 && col >= 0 )
            cout << "this location is fixed"<< endl << "please input again"<<endl;
        // input incorrect
        else if (move == 'A')
            cout << "invalid input" << endl << "please try again"<< endl;

        if (move == 'D' && playboard[row][col]!=0 && row <9 && row>=0 && col <9 && col>=0 && ok_to_play[row][col] == 1) // check if the loc is available to delete
            playboard[row][col] = 0;
        // empty at loc no need to delete
        else if (move == 'D' && playboard[row][col]==0 && row <9 && row>=0 && col <9 && col>=0 && ok_to_play[row][col] == 1)// diff cases diff output
            cout << "this location has not been registered"<< endl << "please try again"<< endl;
        // the loc is a fixed input with the playboard
        else if (move == 'D' && ok_to_play[row][col] == 0 && row <9 && row>=0 && col <9 && col>=0)
            cout << "this location is fixed"<<endl << "please input again" << endl;
        // the input is not valid
        else if (move == 'D')
            cout << "invalid input" << endl << "please try again"<<endl;

    }

    string next;
    nextchoice();
    cin >> next; // next is the input after the user choose 'L' that allow users to decide to check/save the game progress
    
    while (next!="SAVE" && next!="CHECK"){
        cout << ":,) invalid input" << endl << "please try again"<<endl;
        cout << "your choice: ";
        cin >> next;
    }
    
    if (next == "SAVE"){
        SaveBoard(board);       // save playboard and board and ok_to_play
        SavePBoard(playboard);
        SaveOBoard(ok_to_play);
        save();
    }
    if (next == "CHECK"){       // check if the board is correctly filled
        if (check(playboard))
            wincongrats();
        else
            lose();
    }

}
