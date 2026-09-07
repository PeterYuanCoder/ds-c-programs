#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>  //也可以移到game.h当中
#include "game.h"
void menu()
{
	printf("---------------------\n");
	printf("------  1.play  -----\n");
	printf("------  0.exit  -----\n");
	printf("---------------------\n");

}

void game()
{
	char mine[ROWS][COLS ]; //存放的是雷的信息
	char show[ROWS][COLS];  //存放的是排查出的雷的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS,'0');  //引用第四个参数进行初始化
	InitBoard(show, ROWS, COLS,'*');
	//打印棋盘
	DisplayBoard(show,ROW,COL);   //打印的是show的信息，再输出行和列
	//设置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);   //注意是用  mine  打印初始化雷的位置
	//排查雷
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));   //设置随机数的种子
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();   //游戏逻辑
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，请重新选择：\n");

		}

	} while (input);  //当input等于0时终止循环
	return 0;
}