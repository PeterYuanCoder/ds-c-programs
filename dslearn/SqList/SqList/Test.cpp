#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"

#include <stdio.h>

// 清空输入缓冲区(清掉 scanf 残留的换行符)
static void ClearInput()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

int main()
{
	SqList list;
	int choice = 0;
	int pos = 0, val = 0;

	SqListInit(&list);

	while (1)
	{
		printf("\n===== 顺序表菜单 =====\n");
		printf("1. 尾插元素\n");
		printf("2. 头插元素\n");
		printf("3. 指定位置插入\n");
		printf("4. 按位置删除\n");
		printf("5. 按位置修改\n");
		printf("6. 按位置查找\n");
		printf("7. 按值查找位置\n");
		printf("8. 打印顺序表\n");
		printf("9. 查看长度/是否为空\n");
		printf("0. 退出\n");
		printf("请选择: ");

		if (scanf("%d", &choice) != 1)
		{
			ClearInput();
			printf("输入无效，请重新选择。\n");
			continue;
		}
		ClearInput();

		if (choice == 0)
		{
			SqListDestroy(&list);
			printf("已释放顺序表，退出。\n");
			break;
		}

		switch (choice)
		{
		case 1: // 尾插
			printf("请输入要插入的值: ");
			if (scanf("%d", &val) != 1) { ClearInput(); break; }
			ClearInput();
			SqListPushBack(&list, val);
			printf("尾插成功。\n");
			break;

		case 2: // 头插
			printf("请输入要插入的值: ");
			if (scanf("%d", &val) != 1) { ClearInput(); break; }
			ClearInput();
			SqListPushFront(&list, val);
			printf("头插成功。\n");
			break;

		case 3: // 指定位置插入
			printf("请输入位置(0~%d)和值: ", SqListSize(&list));
			if (scanf("%d %d", &pos, &val) != 2) { ClearInput(); break; }
			ClearInput();
			if (pos < 0 || pos > SqListSize(&list))
				printf("位置不合法。\n");
			else
			{
				SqListInsert(&list, pos, val);
				printf("插入成功。\n");
			}
			break;

		case 4: // 按位置删除
			if (EmptySqList(&list))
			{
				printf("表为空，无法删除。\n");
				break;
			}
			printf("请输入位置(0~%d): ", SqListSize(&list) - 1);
			if (scanf("%d", &pos) != 1) { ClearInput(); break; }
			ClearInput();
			if (pos < 0 || pos >= SqListSize(&list))
				printf("位置不合法。\n");
			else
				printf("已删除元素值: %d\n", SqListDelete(&list, pos));
			break;

		case 5: // 按位置修改
			if (EmptySqList(&list))
			{
				printf("表为空，无法修改。\n");
				break;
			}
			printf("请输入位置(0~%d)和新值: ", SqListSize(&list) - 1);
			if (scanf("%d %d", &pos, &val) != 2) { ClearInput(); break; }
			ClearInput();
			if (pos < 0 || pos >= SqListSize(&list))
				printf("位置不合法。\n");
			else
			{
				SqListModify(&list, pos, val);
				printf("修改成功。\n");
			}
			break;

		case 6: // 按位置查找
			if (EmptySqList(&list))
			{
				printf("表为空，无法查找。\n");
				break;
			}
			printf("请输入位置(0~%d): ", SqListSize(&list) - 1);
			if (scanf("%d", &pos) != 1) { ClearInput(); break; }
			ClearInput();
			if (pos < 0 || pos >= SqListSize(&list))
				printf("位置不合法。\n");
			else
				printf("该位置的值为: %d\n", GetElem(&list, pos));
			break;

		case 7: // 按值查找
			if (EmptySqList(&list))
			{
				printf("表为空，无法查找。\n");
				break;
			}
			printf("请输入要查找的值: ");
			if (scanf("%d", &val) != 1) { ClearInput(); break; }
			ClearInput();
			pos = LocateElem(&list, val);
			if (pos == -1)
				printf("未找到该值。\n");
			else
				printf("该值所在位置(下标): %d\n", pos);
			break;

		case 8: // 打印
			SqListPrint(&list);
			break;

		case 9: // 查看长度/是否为空
			printf("长度: %d %s\n", SqListSize(&list),
				EmptySqList(&list) ? "(空表)" : "");
			break;

		default:
			printf("无效选项，请重新选择。\n");
			break;
		}
	}
	return 0;
}