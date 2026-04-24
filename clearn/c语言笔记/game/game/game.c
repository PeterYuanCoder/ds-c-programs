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
	int count = EASY_COUNT;
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
int GetmineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < r * c - EASY_COUNT)
	{

		printf("请输入要排查的坐标为：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标已经被排查过了，不用重复排查\n");

			}
			else
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					//统计周围有几个雷
					int count = GetmineCount(mine, x, y);
					show[x][y] = (char)count + '0';
					DisplayBoard(show, ROW, COL);
					win++;
				}
			}
		}
		else
		{
			printf("输入的坐标非法，重新输入：\n");
		}
	}
	
	if (win == r * c - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}