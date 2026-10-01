#define _CRT_SECURE_NO_WARNINGS

#include "List.h"
#include "DCList.h"

void SingleListMenu();
void DCListMenu();

// ==================== 顶层菜单 ====================

void ShowRootMenu()
{
    printf("=========== 链表测试总菜单 ===========\n");
    printf("1. 单链表\n");
    printf("2. 双向循环链表\n");
    printf("0. 退出\n");
    printf("===================================\n");
}

// ==================== 单链表菜单 ====================

void ShowListMenu()
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

void SingleListMenu()
{
    // 初始化链表
    LNode* L = ListInit();
    int choice = -1;
    int i;
    LDataType x;

    while (1)
    {
        ShowListMenu();
        printf("请选择：");
        if (scanf("%d", &choice) != 1)
        {
            break;
        }
        switch (choice)
        {
        case 0: // 退出
            printf("再见！\n");
            return;
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
            printf("链表已销毁，返回总菜单！\n");
            return;
        }
        default:
            printf("无效选项，请重新输入！\n");
            break;
        }
    }
    ListDestroy(L);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                                           双向循环链表

// ==================== 双向循环链表菜单 ====================

// 求长度（菜单侧的本地辅助函数）
// DCList.h 没有提供 DCListSize/DCListEmpty，为了不去动库接口，这里单独写一个遍历函数
// 循环链表没有NULL做结束标志，所以是靠"走回头结点"来停的
static int DCListLength(DCListNode* L)
{
    int n = 0;
    DCListNode* cur = L->next;
    while (cur != L)
    {
        n++;
        cur = cur->next;
    }
    return n;
}

void ShowDCListMenu()
{
    printf("========= 双向循环链表测试菜单 =========\n");
    printf("1. 打印链表（正向 + 反向）\n");
    printf("2. 求链表长度\n");
    printf("3. 判断链表是否为空\n");
    printf("4. 按位查找（返回结点地址）\n");
    printf("5. 头插\n");
    printf("6. 尾插\n");
    printf("7. 在第i个结点后插入值x\n");
    printf("8. 头删\n");
    printf("9. 尾删\n");
    printf("10. 删除第i个结点\n");
    printf("11. 销毁链表\n");
    printf("0. 退出\n");
    printf("=======================================\n");
}

void DCListMenu()
{
    // 初始化：空表的L->next和L->prev都指向自己
    DCListNode* L = DCListInit();
    int choice = -1;
    int i;
    DCLDataType x;

    while (1)
    {
        ShowDCListMenu();
        printf("请选择：");
        if (scanf("%d", &choice) != 1)
        {
            break;
        }
        switch (choice)
        {
        case 0: // 退出
            printf("再见！\n");
            return;
        case 1: // 打印链表
        {
            DCListPrint(L);
            printf("\n");
            break;
        }
        case 2: // 求链表长度
        {
            printf("链表长度为：%d\n", DCListLength(L));
            break;
        }
        case 3: // 判断链表是否为空
        {
            if (DCListLength(L) == 0)
            {
                printf("链表为空！\n");
            }
            else
            {
                printf("链表非空！\n");
            }
            break;
        }
        case 4: // 按位查找
        {
            DCListNode* p = NULL;
            printf("请输入位置i（从0开始）：");
            scanf("%d", &i);
            if (i < 0)
            {
                printf("位序不能为负数！\n");
                break;
            }
            p = DCListGetElem(L, i);
            if (p != NULL)
                printf("第 %d 个结点的值为：%d，地址：%p\n", i, p->data, (void*)p);
            else
                printf("位序越界（或链表为空）\n");
            break;
        }
        case 5: // 头插
        {
            printf("请输入头插的值：");
            scanf("%d", &x);
            DCListPushFront(L, x);
            printf("头插成功：插入了值 %d\n", x);
            DCListPrint(L);
            printf("\n");
            break;
        }
        case 6: // 尾插
        {
            printf("请输入尾插的值：");
            scanf("%d", &x);
            DCListPushBack(L, x);
            printf("尾插成功：插入了值 %d\n", x);
            DCListPrint(L);
            printf("\n");
            break;
        }
        case 7: // 在第i个结点后插入值x
        {
            // 注意：这里i是"已有结点"的位序，和单链表菜单第10项"新元素落在第i位"不是同一个语义
            // 插入是"在某结点之后"，所以i必须先指向一个已存在的结点；空表请改用第5或6项
            DCListNode* pos = NULL;
            printf("请输入位置i和插入的值x：");
            scanf("%d %d", &i, &x);
            if (i < 0)
            {
                printf("位序不能为负数！\n");
                break;
            }
            pos = DCListGetElem(L, i);
            if (pos == NULL)
            {
                printf("位序越界（或链表为空），无法在该结点后插入！\n");
                break;
            }
            DCListInsert(pos, x);
            printf("插入成功：在第 %d 个结点后插入了值 %d\n", i, x);
            DCListPrint(L);
            printf("\n");
            break;
        }
        case 8: // 头删
        {
            if (DCListLength(L) == 0)
            {
                printf("链表为空，不能头删！\n");
            }
            else
            {
                DCListPopFront(L);
                printf("头删成功\n");
                DCListPrint(L);
                printf("\n");
            }
            break;
        }
        case 9: // 尾删
        {
            if (DCListLength(L) == 0)
            {
                printf("链表为空，不能尾删！\n");
            }
            else
            {
                DCListPopBack(L);
                printf("尾删成功\n");
                DCListPrint(L);
                printf("\n");
            }
            break;
        }
        case 10: // 删除第i个结点
        {
            DCListNode* pos = NULL;
            if (DCListLength(L) == 0)
            {
                printf("链表为空，不能删除！\n");
                break;
            }
            printf("请输入要删除的位置i：");
            scanf("%d", &i);
            if (i < 0)
            {
                printf("位序不能为负数！\n");
                break;
            }
            pos = DCListGetElem(L, i);
            if (pos == NULL)
            {
                printf("位序越界！\n");
                break;
            }
            // DCListDelete禁止传入头结点，而DCListGetElem永远不会返回头结点
            //（越界时返回NULL），所以这里的pos一定是个数据结点，可以放心传
            printf("已删除第 %d 个结点，其值为：%d\n", i, pos->data);
            DCListDelete(pos);
            DCListPrint(L);
            printf("\n");
            break;
        }
        case 11: // 销毁链表
        {
            DCListDestroy(L);
            L = NULL;
            printf("链表已销毁，返回总菜单！\n");
            return;
        }
        default:
            printf("无效选项，请重新输入！\n");
            break;
        }
    }
    DCListDestroy(L);
}

// ==================== 程序入口 ====================

int main()
{
    int choice = -1;

    while (1)
    {
        ShowRootMenu();
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
        case 1: // 单链表
            SingleListMenu();
            break;
        case 2: // 双向循环链表
            DCListMenu();
            break;
        default:
            printf("无效选项，请重新输入！\n");
            break;
        }
    }
    return 0;
}