#include <iostream>
#include <iomanip>

using namespace std;
struct num_n_reg{
    int digit;
    int play;
};
void PrintBoard(int b[9][9],int ok_to_play[9][9]){ // printing the board
    cout << endl;
    cout << setw(0) << 0 << setw(10) << "|3" << setw(11) << "|6" << endl;
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            cout << b[i][j];
            if (ok_to_play[i][j]==1)
                cout << "  ";
            else
                cout << "* ";
            if ((j+1)%3==0 && j!=8) // separate the 3*3 blocks by "|" vertically
                cout << "| ";
            if ((i+1)%3==0 && j ==8 && i!=8)
                cout << endl << "---------+----------+--------"; // separate the blocks horizontally
        }
        if (i == 0 || i == 3 || i == 6)
            cout << "<-"<< i;
        cout << endl;
    }
}


void welcome(){      //print welcome
    cout << "                  +---------+"<<endl;
    cout << "                  | 1  2  3 |"<<endl;
    cout << "                  | 4     6 |"<<endl;
    cout << "                  | 7  8  9 |"<<endl;
    cout << "                  +---------+"<<endl;
    cout << "              * ~ * SUDOKU * ~ *" << endl;
}

void startintro(){      //print startintro
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout << "| 1. NEW GAME | 2. CONTINUE LAST GAME | 3. EXIT |"<<endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout << "|    PLEASE ENTER THE OPTION WITH AN INTERGER   |" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl<<endl<<"choice: ";
}

void playintro(){      //print playintro
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "|   1. EASY   | 2. INTERMEDIATE  |   3. HARD    |" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout << "|             PLEASE CHOOSE A LEVEL             |" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl<< "choice: ";
}

void wincongrats(){      //print wincongrats
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout <<"|                 ((ヽ(๑╹◡╹๑)ﾉ))♬               |" << endl;
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout <<"|             ~ CONGRATIONS YOU WON ~           |" << endl;
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
    startintro();
    
}

void lose(){      //print lose
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout << "|                 ( ´･･)ﾉ(._.`)                 |"<< endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout << "|    DONT WORRY YOU WILL DO BETTER NEXT TIME    |"<< endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout << "|               (┘￣︶￣)┘└(￣︶￣└)            |" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl << endl;
    startintro();
}

void save(){      //print save
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout <<"|                   ♪(┌・。・)┌                 |" << endl;
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout <<"|          YOUR RECORD HAVE BEEN SAVED          |" << endl;
    cout <<"|                SEE YA NEXT TIME               |" << endl;
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl << endl;
    startintro();
}

void move(){      //print move
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout <<"|      A. ADD A DIGIT | B. DELETE AN INPUT      |"<<endl;
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout <<"|        H. HINT      |   L. LEAVE THE GAME     |"<<endl;
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl<<endl;;
}

void nextchoice(){      //print nextchoice
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout << "|         SAVE: your input will be saved        |" << endl;
    cout << "|     in 3 txt file at the current directory    |" << endl;
    cout << "|   named board.txt playboard.txt oktoplay.txt  |" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout << "|        CHECK: your board will be checked      |" << endl;
    cout << "|        and the record will not be saved       |" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl<<endl<<"ur choice: ";
}
