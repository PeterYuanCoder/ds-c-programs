#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

void ShowMenu()
{
    printf("=========== 链表测试菜单 ===========\n");
    printf("1. 打印链表\n");
    printf("2. 求链表长度\n");
    printf("3. 判断链表是否为空\n");
    printf("4. 按值查找（返回结点地址）\n");
    printf("5. 按位查找（返回结点地址）\n");
    printf("6. 头插\n");
    printf("7. 尾插\n");
    printf("8. 头删\n");
    printf("9. 尾删\n");
    printf("10. 在第i个位置插入元素x\n");
    printf("11. 删除第i个结点\n");
    printf("12. 销毁链表\n");
    printf("0. 退出\n");
    printf("===================================\n");
}

int main()
{
    // 初始化链表
    LNode* L = ListInit();
    int choice = -1;
    int i;
    LDataType x;

    while (1)
    {
        ShowMenu();
        printf("请选择：");
        if (scanf("%d", &choice) != 1)
        {
            break;
        }
        switch (choice)
        {
        case 0: // 退出
            printf("再见！\n");
            return 0;
        case 1: // 打印链表
        {
            ListPrint(L);
            printf("\n");
            break;
        }
        case 2: // 求链表长度
        {
            printf("链表长度为：%d\n", ListSize(L));
            break;
        }
        case 3: // 判断链表是否为空
        {
            if (ListEmpty(L))
            {
                printf("链表为空！\n");
            }
            else
            {
                printf("链表非空！\n");
            }
            break;
        }
        case 4: // 按值查找
        {
            LNode* p = NULL;
            printf("请输入要查找的值：");
            scanf("%d", &x);
            p = ListLocateElem(L, x);
            if (p != NULL)
                printf("找到结点，其值为：%d，地址：%p\n", p->data, (void*)p);
            else
                printf("链表中不存在值 %d\n", x);
            break;
        }
        case 5: // 按位查找
        {
            LNode* p = NULL;
            printf("请输入位置i（从0开始）：");
            scanf("%d", &i);
            p = ListGetElem(L, i);
            if (p != NULL)
                printf("第 %d 个结点的值为：%d\n", i, p->data);
            else
                printf("位序越界\n");
            break;
        }
        case 6: // 头插
        {
            printf("请输入头插的值：");
            scanf("%d", &x);
            ListPushFront(L, x);
            printf("头插成功：插入了值 %d\n", x);
            ListPrint(L);
            printf("\n");
            break;
        }
        case 7: // 尾插
        {
            printf("请输入尾插的值：");
            scanf("%d", &x);
            ListPushBack(L, x);
            printf("尾插成功：插入了值 %d\n", x);
            ListPrint(L);
            printf("\n");
            break;
        }
        case 8: // 头删
        {
            if (ListEmpty(L))
            {
                printf("链表为空，不能头删！\n");
            }
            else
            {
                x = ListPopFront(L);
                printf("头删成功：删除了值 %d\n", x);
                ListPrint(L);
                printf("\n");
            }
            break;
        }
        case 9: // 尾删
        {
            if (ListEmpty(L))
            {
                printf("链表为空，不能尾删！\n");
            }
            else
            {
                x = ListPopBack(L);
                printf("尾删成功：删除了值 %d\n", x);
                ListPrint(L);
                printf("\n");
            }
            break;
        }
        case 10: // 在第i个位置插入元素x
        {
            printf("请输入位置i和插入的值x：");
            scanf("%d %d", &i, &x);
            ListInsert(L, i, x);
            printf("插入成功：在第 %d 个位置插入了值 %d\n", i, x);
            ListPrint(L);
            printf("\n");
            break;
        }
        case 11: // 删除第i个结点
        {
            if (ListEmpty(L))
            {
                printf("链表为空，不能删除！\n");
            }
            else
            {
                printf("请输入要删除的位置i：");
                scanf("%d", &i);
                x = ListDelete(L, i);
                printf("删除成功：删除了值 %d\n", x);
                ListPrint(L);
                printf("\n");
            }
            break;
        }
        case 12: // 销毁链表
        {
            ListDestroy(L);
            L = NULL;
            printf("链表已销毁，程序退出！\n");
            return 0;
        }
        default:
            printf("无效选项，请重新输入！\n");
            break;
        }
    }
    return 0;
}