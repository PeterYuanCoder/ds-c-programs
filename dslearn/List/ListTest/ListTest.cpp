// ListTest.cpp
//
// 本文件用于对「链表」List.h / List.cpp 中的全部接口编写 Google Test 单元测试。
// 被测工程：ListTest（Visual Studio 2022 默认支持的 Google Test 框架构建）。
// 被测源码：直接编译上级目录 List\List.cpp 中的实现，不依赖 List 工程的 main。
//
// 覆盖接口清单（共 14 个）：
//   BuyListNode / ListInit / ListPrint / ListSize / ListEmpty /
//   ListLocateElem / ListGetElem / ListInsert / ListDelete /
//   ListPushFront / ListPushBack / ListPopFront / ListPopBack / ListDestroy
//
// 说明：
//   1. 本工程首个有效节点为头节点之后的节点（头节点 data == -1，next 指向首元素）。
//   2. ListPopFront / ListPopBack / ListDelete 对空表或非法下标有 assert，
//      Debug 下会直接终止进程，因此测试只覆盖合法输入。
//   3. 每个测试用例都会自行初始化链表，并在结束时调用 ListDestroy 释放内存。

#define _CRT_SECURE_NO_WARNINGS

#include "gtest/gtest.h"
#include "List.h"

#include <string>
#include <vector>

namespace
{
    // 辅助函数：顺序尾插一组元素，用于构造已知内容的链表
    void PushBackValues(LNode* L, const std::vector<int>& values)
    {
        for (std::vector<int>::size_type i = 0; i < values.size(); ++i)
        {
            ListPushBack(L, values[i]);
        }
    }

    // 辅助函数：校验链表内容与期望序列完全一致（长度、各节点值、无冗余节点）
    void ExpectListEquals(LNode* L, const std::vector<int>& expected)
    {
        EXPECT_EQ(ListSize(L), static_cast<int>(expected.size()));
        LNode* cur = L->next;
        for (std::vector<int>::size_type i = 0; i < expected.size(); ++i)
        {
            ASSERT_NE(cur, nullptr) << "链表过早结束，失败位置 i=" << i;
            EXPECT_EQ(cur->data, expected[i]) << "节点数据不符，失败位置 i=" << i;
            cur = cur->next;
        }
        // 链表末尾应为 NULL，不允许出现多余节点
        EXPECT_EQ(cur, nullptr);
    }
} // 匿名命名空间结束

//
// 1. BuyListNode：申请并初始化一个新节点
//

// 创建节点：malloc 成功应返回非空指针
TEST(BuyListNodeTest, ReturnsNonNullNode)
{
    LNode* node = BuyListNode(10);
    // 节点创建成功，指针非空
    EXPECT_NE(node, static_cast<LNode*>(nullptr));
    if (node != nullptr)
    {
        free(node); // 手工释放，避免内存泄漏
    }
}

// 创建节点：节点的数据域保存了传入的值
TEST(BuyListNodeTest, StoringData)
{
    LNode* node = BuyListNode(42);
    ASSERT_NE(node, static_cast<LNode*>(nullptr));
    // 新节点的 data 应等于传入参数
    EXPECT_EQ(node->data, 42);
    free(node);
}

// 创建节点：新节点的 next 指针应初始化为 NULL
TEST(BuyListNodeTest, NextPointerIsNull)
{
    LNode* node = BuyListNode(-5);
    ASSERT_NE(node, static_cast<LNode*>(nullptr));
    // 新节点尚未链接到任何节点，next 应为空
    EXPECT_EQ(node->next, static_cast<LNode*>(nullptr));
    free(node);
}

//
// 2. ListInit：初始化链表（带头节点的空链表）
//

// 初始化：返回非空头节点指针
TEST(ListInitTest, InitReturnsNonNullHead)
{
    LNode* L = ListInit();
    // 初始化失败（malloc 失败）才会返回空，正常应非空
    EXPECT_NE(L, static_cast<LNode*>(nullptr));
    if (L != nullptr)
    {
        ListDestroy(L);
    }
}

// 初始化：头节点的数据域约定为 -1（哨兵值，不参与业务数据）
TEST(ListInitTest, HeadDataIsMinusOne)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    // 头节点 data 为约定的 -1
    EXPECT_EQ(L->data, -1);
    ListDestroy(L);
}

// 初始化：新链表应为空（无有效元素）
TEST(ListInitTest, InitProduceEmptyList)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    // 新链表没有有效元素
    EXPECT_TRUE(ListEmpty(L));
    // 同时长度为 0
    EXPECT_EQ(ListSize(L), 0);
    ListDestroy(L);
}

//
// 3. ListPrint：打印链表（不返回，只能验证不崩溃与打印内容）
//

// 打印：空表打印不崩溃，且输出包含结束标记 "NULL"
TEST(ListPrintTest, PrintEmptyList)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    testing::internal::CaptureStdout();
    ListPrint(L);   // 空表打印不应崩溃
    std::string out = testing::internal::GetCapturedStdout();
    // 输出应当包含链尾的 NULL 标记
    EXPECT_NE(out.find("NULL"), std::string::npos);
    ListDestroy(L);
}

// 打印：非空表输出应包含各节点元素与 NULL 结尾
TEST(ListPrintTest, PrintNonEmptyList)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    testing::internal::CaptureStdout();
    ListPrint(L);   // 非空表打印不应崩溃
    std::string out = testing::internal::GetCapturedStdout();
    // 输出应包含元素值 "1" 与结尾标记 "NULL"
    EXPECT_NE(out.find("1"), std::string::npos);
    EXPECT_NE(out.find("NULL"), std::string::npos);
    ListDestroy(L);
}

//
// 4. ListSize：获取链表中有效元素个数
//

// 长度：空表长度为 0
TEST(ListSizeTest, EmptyListSizeIsZero)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    // 空表无有效元素
    EXPECT_EQ(ListSize(L), 0);
    ListDestroy(L);
}

// 长度：尾插 3 个元素后长度为 3
TEST(ListSizeTest, SizeAfterPushBack)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    // 每次尾插计数应加 1，共 3 个
    EXPECT_EQ(ListSize(L), 3);
    ListDestroy(L);
}

// 长度：头插 5 个元素后长度为 5
TEST(ListSizeTest, SizeAfterPushFront)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    for (int i = 1; i <= 5; ++i)
    {
        ListPushFront(L, i);
    }
    // 共执行 5 次头插，长度为 5
    EXPECT_EQ(ListSize(L), 5);
    ListDestroy(L);
}

//
// 5. ListEmpty：判断链表是否为空
//

// 判空：新链表为空
TEST(ListEmptyTest, EmptyListIsEmpty)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    // 刚初始化应为空
    EXPECT_TRUE(ListEmpty(L));
    ListDestroy(L);
}

// 判空：插入元素后链表非空
TEST(ListEmptyTest, NonEmptyListIsNotEmpty)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    ListPushFront(L, 1);
    // 插入后不再为空
    EXPECT_FALSE(ListEmpty(L));
    ListDestroy(L);
}

// 判空：把元素全部弹出后重新变为空
TEST(ListEmptyTest, EmptyAfterPoppingAll)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2});
    // 弹空所有元素
    ListPopFront(L);
    ListPopFront(L);
    // 弹空后再次为空
    EXPECT_TRUE(ListEmpty(L));
    ListDestroy(L);
}

//
// 6. ListLocateElem：按值查找，返回第一个匹配节点的地址
//

// 查找：存在的值应返回对应节点，且数据正确
TEST(ListLocateElemTest, FindExistingValue)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{10, 20, 30});
    LNode* found = ListLocateElem(L, 20);
    // 应找到值为 20 的节点
    ASSERT_NE(found, static_cast<LNode*>(nullptr));
    EXPECT_EQ(found->data, 20);
    ListDestroy(L);
}

// 查找：不存在的值应返回 NULL
TEST(ListLocateElemTest, NotFoundReturnsNull)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{10, 20});
    // 链表中没有 99，应返回空指针
    EXPECT_EQ(ListLocateElem(L, 99), static_cast<LNode*>(nullptr));
    ListDestroy(L);
}

// 查找：重复值应返回第一个（最早插入的）匹配节点
TEST(ListLocateElemTest, FindFirstOccurrence)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 1});
    LNode* first = ListLocateElem(L, 1);
    // 命中节点应为头节点后的第一个节点（data == 1）
    EXPECT_EQ(first, L->next);
    ListDestroy(L);
}

//
// 7. ListGetElem：按下标取值，返回对应节点地址（越界返回 NULL）
//

// 取值：i=0 返回第一个元素
TEST(ListGetElemTest, GetHeadElement)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{5, 6, 7});
    LNode* node = ListGetElem(L, 0);
    // 下标 0 为第一个元素
    ASSERT_NE(node, static_cast<LNode*>(nullptr));
    EXPECT_EQ(node->data, 5);
    ListDestroy(L);
}

// 取值：返回中间位置的节点
TEST(ListGetElemTest, GetMiddleElement)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{5, 6, 7});
    LNode* node = ListGetElem(L, 1);
    // 下标 1 为第二个元素
    ASSERT_NE(node, static_cast<LNode*>(nullptr));
    EXPECT_EQ(node->data, 6);
    ListDestroy(L);
}

// 取值：返回末尾节点
TEST(ListGetElemTest, GetTailElement)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{5, 6, 7});
    LNode* node = ListGetElem(L, 2);
    // 下标 2（size-1）为最后一个元素
    ASSERT_NE(node, static_cast<LNode*>(nullptr));
    EXPECT_EQ(node->data, 7);
    ListDestroy(L);
}

// 取值：下标越界返回 NULL
TEST(ListGetElemTest, OutOfRangeReturnsNull)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{5, 6});
    // 下标 >= 长度即为越界，应返回空指针
    EXPECT_EQ(ListGetElem(L, 2), static_cast<LNode*>(nullptr));
    EXPECT_EQ(ListGetElem(L, 99), static_cast<LNode*>(nullptr));
    ListDestroy(L);
}

//
// 8. ListInsert：在指定下标位置插入新元素（合法范围 i ∈ [0, size]）
//

// 插入：在下标 0（头）插入，成为新的首元素
TEST(ListInsertTest, InsertAtHead)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{2, 3});
    ListInsert(L, 0, 1);   // 在头部插入 1
    // 插入后顺序应为 1,2,3
    ExpectListEquals(L, std::vector<int>{1, 2, 3});
    ListDestroy(L);
}

// 插入：在中间位置插入，不破坏原有顺序
TEST(ListInsertTest, InsertInMiddle)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 3, 4});
    ListInsert(L, 1, 2);   // 在下标 1 处插入 2
    // 插入后顺序应为 1,2,3,4
    ExpectListEquals(L, std::vector<int>{1, 2, 3, 4});
    ListDestroy(L);
}

// 插入：在 i == size 处插入即尾插
TEST(ListInsertTest, InsertAtTail)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2});
    ListInsert(L, 2, 3);   // 在下标 2（末尾）插入 3
    // 插入后顺序应为 1,2,3
    ExpectListEquals(L, std::vector<int>{1, 2, 3});
    ListDestroy(L);
}

// 插入：插入后长度加 1
TEST(ListInsertTest, InsertIncrementsSize)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2});
    int before = ListSize(L);
    ListInsert(L, 1, 99);
    // 长度应在插入后增加 1
    EXPECT_EQ(ListSize(L), before + 1);
    ListDestroy(L);
}

//
// 9. ListDelete：删除指定下标节点并返回其值（合法范围 i ∈ [0, size-1]）
//

// 删除：删除头部节点并返回其值
TEST(ListDeleteTest, DeleteHeadReturnsFirstValue)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    int value = ListDelete(L, 0);
    // 返回被删的头部值
    EXPECT_EQ(value, 1);
    // 剩余元素保持顺序 2,3
    ExpectListEquals(L, std::vector<int>{2, 3});
    ListDestroy(L);
}

// 删除：删除中间节点，其余元素顺序不变
TEST(ListDeleteTest, DeleteMiddle)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    int value = ListDelete(L, 1);
    // 返回被删的中间值
    EXPECT_EQ(value, 2);
    // 剩余元素顺序应为 1,3
    ExpectListEquals(L, std::vector<int>{1, 3});
    ListDestroy(L);
}

// 删除：删除尾部节点并返回其值
TEST(ListDeleteTest, DeleteTailReturnsLastValue)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    int value = ListDelete(L, 2);
    // 返回被删的尾部值
    EXPECT_EQ(value, 3);
    // 剩余元素顺序应为 1,2
    ExpectListEquals(L, std::vector<int>{1, 2});
    ListDestroy(L);
}

// 删除：删除后长度减 1
TEST(ListDeleteTest, DeleteDecrementsSize)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    int before = ListSize(L);
    ListDelete(L, 1);
    // 长度应在删除后减少 1
    EXPECT_EQ(ListSize(L), before - 1);
    ListDestroy(L);
}

//
// 10. ListPushFront：头插
//

// 头插：依次头插 1,2,3，最终顺序应为 3,2,1（类似栈）
TEST(ListPushFrontTest, PushOrderReversed)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    ListPushFront(L, 1);
    ListPushFront(L, 2);
    ListPushFront(L, 3);
    // 后插入的在前面，顺序为 3,2,1
    ExpectListEquals(L, std::vector<int>{3, 2, 1});
    ListDestroy(L);
}

// 头插：向空链表头插单个元素
TEST(ListPushFrontTest, PushOntoEmpty)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    ListPushFront(L, 7);
    // 空表头插后只有一个元素
    ExpectListEquals(L, std::vector<int>{7});
    ListDestroy(L);
}

//
// 11. ListPushBack：尾插
//

// 尾插：依次尾插 1,2,3，最终顺序保持 1,2,3（类似队列）
TEST(ListPushBackTest, PushOrderKept)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    // 尾插保持原顺序
    ExpectListEquals(L, std::vector<int>{1, 2, 3});
    ListDestroy(L);
}

// 尾插：向空链表尾插单个元素
TEST(ListPushBackTest, PushOntoEmpty)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    ListPushBack(L, 8);
    // 空表尾插后只有一个元素
    ExpectListEquals(L, std::vector<int>{8});
    ListDestroy(L);
}

//
// 12. ListPopFront：头删，返回被删节点值（非空链表）
//

// 头删：返回原首元素的值
TEST(ListPopFrontTest, PopReturnsHeadValue)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    int value = ListPopFront(L);
    // 弹出的应是首元素
    EXPECT_EQ(value, 1);
    ListDestroy(L);
}

// 头删：删除首元素后，链表剩余顺序与长度正确
TEST(ListPopFrontTest, PopRemovesHead)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    int sizeBefore = ListSize(L);
    ListPopFront(L);
    // 长度减 1
    EXPECT_EQ(ListSize(L), sizeBefore - 1);
    // 剩余元素顺序应为 2,3
    ExpectListEquals(L, std::vector<int>{2, 3});
    ListDestroy(L);
}

// 头删：逐个弹出直到为空（最后的空判断由 ListEmpty 完成）
TEST(ListPopFrontTest, PopUntilEmpty)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2});
    EXPECT_EQ(ListPopFront(L), 1);
    EXPECT_EQ(ListPopFront(L), 2);
    // 全部弹出后为空
    EXPECT_TRUE(ListEmpty(L));
    ListDestroy(L);
}

//
// 13. ListPopBack：尾删，返回被删节点值（非空链表）
//

// 尾删：返回原尾元素的值
TEST(ListPopBackTest, PopReturnsTailValue)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    int value = ListPopBack(L);
    // 弹出的应是尾元素
    EXPECT_EQ(value, 3);
    ListDestroy(L);
}

// 尾删：删除尾元素后，链表剩余顺序与长度正确
TEST(ListPopBackTest, PopRemovesTail)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    int sizeBefore = ListSize(L);
    ListPopBack(L);
    // 长度减 1
    EXPECT_EQ(ListSize(L), sizeBefore - 1);
    // 剩余元素顺序应为 1,2
    ExpectListEquals(L, std::vector<int>{1, 2});
    ListDestroy(L);
}

// 尾删：单元素链表尾删后变为空
TEST(ListPopBackTest, PopSingleElement)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    ListPushBack(L, 5);
    int value = ListPopBack(L);
    // 弹出唯一元素，值是它本身
    EXPECT_EQ(value, 5);
    // 链表变空
    EXPECT_TRUE(ListEmpty(L));
    ListDestroy(L);
}

//
// 14. ListDestroy：销毁整个链表，释放所有节点内存
//

// 销毁：空表销毁不崩溃
TEST(ListDestroyTest, DestroyEmptyList)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    // 销毁空表不应崩溃、不应发生内存错误
    ListDestroy(L);
    L = nullptr; // 释放后将指针置空，避免误用
}

// 销毁：非空表销毁不崩溃
TEST(ListDestroyTest, DestroyNonEmptyList)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));
    PushBackValues(L, std::vector<int>{1, 2, 3});
    // 销毁含 3 个有效节点的链表不应崩溃
    ListDestroy(L);
    L = nullptr;
}

//
// 综合用例：多个接口组合使用，模拟真实场景
//

// 综合：插入、删除、查找、取值配合使用
TEST(ListFlowTest, InsertDeleteLocateGetTogether)
{
    LNode* L = ListInit();
    ASSERT_NE(L, static_cast<LNode*>(nullptr));

    // 依次尾插 1,2,3，再头插 0 → 0,1,2,3
    PushBackValues(L, std::vector<int>{1, 2, 3});
    ListPushFront(L, 0);
    ExpectListEquals(L, std::vector<int>{0, 1, 2, 3});

    // 在下标 2 处插入 9 → 0,1,9,2,3
    ListInsert(L, 2, 9);
    ExpectListEquals(L, std::vector<int>{0, 1, 9, 2, 3});

    // 删除下标 2 的节点，返回值应为 9
    EXPECT_EQ(ListDelete(L, 2), 9);

    // 按值查找 1，应能命中且数据正确
    LNode* found = ListLocateElem(L, 1);
    ASSERT_NE(found, static_cast<LNode*>(nullptr));
    EXPECT_EQ(found->data, 1);

    // 按下标取尾部元素
    LNode* tail = ListGetElem(L, ListSize(L) - 1);
    ASSERT_NE(tail, static_cast<LNode*>(nullptr));
    EXPECT_EQ(tail->data, 3);

    // 头删与尾删
    EXPECT_EQ(ListPopFront(L), 0);
    EXPECT_EQ(ListPopBack(L), 3);

    // 最终剩余 1,2
    ExpectListEquals(L, std::vector<int>{1, 2});

    ListDestroy(L);
}