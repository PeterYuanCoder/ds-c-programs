#pragma once
//方便修改扫雷的规模
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include<stdlib.h>
#include<time.h>

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int r, int c,char set);
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int r, int c);
//设置雷
void SetMine(char board[ROWS][COLS], int r, int c);