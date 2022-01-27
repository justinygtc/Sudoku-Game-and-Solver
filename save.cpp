#include <iostream>
#include <fstream>
#include <string>
#include "save.h"
using namespace std;

void SaveBoard(int b[9][9]) {       // save board by inputing the variable
    ofstream fout("board.txt");
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            fout << b[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
}

void SavePBoard(int b[9][9]) {       // save playboard by inputing the variable
    ofstream fout("playboard.txt");
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            fout << b[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
}

void SaveOBoard(int b[9][9]) {       // save ok to play by inputing the variable
    ofstream fout("oktoplay.txt");
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            fout << b[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
}

bool ReadBoard(int (&b)[9][9]) {    // read board by inputing the variable to be changed
    ifstream fin("board.txt");
    if (fin.fail()){
        cout << "you sure? there is no record in this directory" << endl;
        cout << "please check if there are files named" << endl;
        cout << "board.txt"<<endl;
        cout << "playboard.txt"<<endl;
        cout << "oktoplay.txt" << endl;
        return 0;
    }
    else{
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                fin >> b[i][j];
            }
        }
    }
    fin.close();
    return 1;
}

void ReadPBoard(int (&b)[9][9]) {   // read playboard by inputing the variable to be changed
    ifstream fin("playboard.txt");
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            fin >> b[i][j];
        }
    }
    fin.close();
}

void ReadOBoard(int (&b)[9][9]) {     // read ok to play by inputing the variable to be changed
    ifstream fin("oktoplay.txt");
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            fin >> b[i][j];
        }
    }
    fin.close();
}
