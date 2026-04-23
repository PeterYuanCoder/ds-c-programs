#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
void InitBoard(char board[ROWS][COLS], int r, int c, char set)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int r, int c)
{
	for (int j = 0; j <= c; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (int i = 1; i <= r; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= c; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
void SetMine(char board[ROWS][COLS], int r, int c)
{
	//雷的个数
	int count = 10;
	while (count)
	{
		int x = rand() % r + 1;  //rand取随机数    
		int y = rand() % c + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}