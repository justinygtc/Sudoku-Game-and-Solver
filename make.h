#ifndef MAKE_H
#define MAKE_H

bool box_ok(int x,int y,int target, int board[9][9]);
int rowcnt(int x, int target, int board[9][9]);
int colcnt(int x, int target, int board[9][9]);
bool check(int board[9][9]);
void startplaying(int playboard[9][9],int board[9][9],int ok_to_play[9][9]);
#endif
