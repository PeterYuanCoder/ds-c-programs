// test.cpp
//
// 顺序表(SqList)全部公共接口的 GoogleTest 单元测试。
// 与 dstore/ds_learn 项目一一对应,覆盖 SqList.h 中声明的 13 个接口:
//   SqListInit / SqListDestroy / GetElem / LocateElem / SqListInsert /
//   SqListDelete / SqListPrint / EmptySqList / SqListSize /
//   SqListPushBack / SqListPushFront / SqListPopBack / SqListPopFront
//
// 测试通过"测试夹具(Test Fixture)"复用公共的初始化/销毁逻辑:
// SetUp()  在每条用例执行前自动创建并初始化一个顺序表;
// TearDown() 在每条用例执行后自动销毁,避免内存泄漏。

#include "pch.h"

#include "../SqList/SqList.h"

namespace {

// ---------------------------------------------------------------------------
// 测试夹具 : 每个测试用例拥有一个独立、已初始化好的顺序表
// ---------------------------------------------------------------------------
class SqListTest : public ::testing::Test {
protected:
	// 每条用例运行前:分配内存并把表初始化为空表
	void SetUp() override {
		SqListInit(&list_);
	}

	// 每条用例运行后:释放内存,防止泄漏
	void TearDown() override {
		SqListDestroy(&list_);
	}

	SqList list_;  // 用例本身要操作的那个顺序表
};

// 辅助函数:往表中连续尾插 n 个元素(1,2,...,n),方便用例造数据
void PushSome(SqList* ps, int n) {
	for (int i = 0; i < n; ++i) {
		SqListPushBack(ps, i + 1);
	}
}

// ---------------------------------------------------------------------------
// 1. SqListInit —— 初始化后应是一个"空表"
// ---------------------------------------------------------------------------
TEST_F(SqListTest, Init_MakesEmptyListWithCapacity4) {
	EXPECT_EQ(SqListSize(&list_), 0);   // 初始化后元素个数应为 0
	EXPECT_TRUE(EmptySqList(&list_));   // 初始化后应为空表
	EXPECT_EQ(list_.capacity, 4);       // 初始容量与实现约定一致(4)
	EXPECT_NE(list_.arr, nullptr);      // Init 应成功申请到动态内存
}

// ---------------------------------------------------------------------------
// 2. SqListSize —— 元素个数随增删操作正确变化
// ---------------------------------------------------------------------------
TEST_F(SqListTest, Size_TracksElementCount) {
	EXPECT_EQ(SqListSize(&list_), 0);   // 空表时长度为 0
	SqListPushBack(&list_, 1);
	SqListPushBack(&list_, 2);          // 现在有 [1, 2]
	EXPECT_EQ(SqListSize(&list_), 2);
	SqListDelete(&list_, 0);            // 删掉头元素,剩 [2]
	EXPECT_EQ(SqListSize(&list_), 1);
}

// ---------------------------------------------------------------------------
// 3. SqListPushBack —— 尾插:元素按插入顺序排列
// ---------------------------------------------------------------------------
TEST_F(SqListTest, PushBack_AppendsInOrder) {
	SqListPushBack(&list_, 10);
	SqListPushBack(&list_, 20);
	SqListPushBack(&list_, 30);
	EXPECT_EQ(SqListSize(&list_), 3);   // 压入 3 个元素
	EXPECT_FALSE(EmptySqList(&list_));  // 有元素后不再是空表
	EXPECT_EQ(GetElem(&list_, 0), 10);  // 首元素为第一次压入的值
	EXPECT_EQ(GetElem(&list_, 1), 20);  // 中间元素顺序保持
	EXPECT_EQ(GetElem(&list_, 2), 30);  // 尾元素为最后一次压入的值
}

// ---------------------------------------------------------------------------
// 4. SqListPushBack —— 超出初始容量(4)时自动扩容翻倍
// ---------------------------------------------------------------------------
TEST_F(SqListTest, PushBack_DoublesCapacityWhenFull) {
	PushSome(&list_, 5);                // 压入 5 个,超过容量 4,触发扩容
	EXPECT_EQ(list_.capacity, 8);       // 扩容规则:容量翻倍 4 -> 8
	EXPECT_EQ(SqListSize(&list_), 5);   // 扩容不影响已有元素个数
	EXPECT_EQ(GetElem(&list_, 4), 5);   // 扩容后新元素仍能正确取到
}

// ---------------------------------------------------------------------------
// 5. SqListPushFront —— 头插:新元素到头部,原元素整体后移
// ---------------------------------------------------------------------------
TEST_F(SqListTest, PushFront_PrependsElement) {
	SqListPushBack(&list_, 1);
	SqListPushBack(&list_, 2);          // 先有 [1, 2]
	SqListPushFront(&list_, 0);         // 头插 0 -> [0, 1, 2]
	EXPECT_EQ(SqListSize(&list_), 3);
	EXPECT_EQ(GetElem(&list_, 0), 0);   // 头部是新插入的元素
	EXPECT_EQ(GetElem(&list_, 1), 1);   // 原元素依次后移
	EXPECT_EQ(GetElem(&list_, 2), 2);
}

// ---------------------------------------------------------------------------
// 6. SqListInsert —— 在下标 0(头部)插入
// ---------------------------------------------------------------------------
TEST_F(SqListTest, Insert_AtHead) {
	PushSome(&list_, 3);                // [1, 2, 3]
	SqListInsert(&list_, 0, 99);        // 在下标 0 插入 -> [99, 1, 2, 3]
	EXPECT_EQ(GetElem(&list_, 0), 99);
	EXPECT_EQ(GetElem(&list_, 1), 1);
	EXPECT_EQ(SqListSize(&list_), 4);
}

// ---------------------------------------------------------------------------
// 7. SqListInsert —— 在中间位置插入
// ---------------------------------------------------------------------------
TEST_F(SqListTest, Insert_AtMiddle) {
	PushSome(&list_, 3);                // [1, 2, 3]
	SqListInsert(&list_, 1, 99);        // 在下标 1 插入 -> [1, 99, 2, 3]
	EXPECT_EQ(GetElem(&list_, 1), 99);  // 新元素就位
	EXPECT_EQ(GetElem(&list_, 2), 2);   // 原第 2 个元素后移了一位
	EXPECT_EQ(SqListSize(&list_), 4);
}

// ---------------------------------------------------------------------------
// 8. SqListInsert —— i == size 等价于尾插
// ---------------------------------------------------------------------------
TEST_F(SqListTest, Insert_AtTail) {
	PushSome(&list_, 2);                // [1, 2]
	SqListInsert(&list_, 2, 3);         // 在下标 2 插入(i==size,即尾插)
	EXPECT_EQ(GetElem(&list_, 2), 3);
	EXPECT_EQ(SqListSize(&list_), 3);
}

// ---------------------------------------------------------------------------
// 9. SqListDelete —— 删除中间元素:返回被删值,后续元素前移
// ---------------------------------------------------------------------------
TEST_F(SqListTest, Delete_MiddleReturnsValueAndShifts) {
	PushSome(&list_, 5);                // [1, 2, 3, 4, 5]
	int removed = SqListDelete(&list_, 2);  // 删除下标 2 的元素(值为 3)
	EXPECT_EQ(removed, 3);              // 返回的是被删除的元素值
	EXPECT_EQ(SqListSize(&list_), 4);   // 删除后少一个元素
	EXPECT_EQ(GetElem(&list_, 2), 4);   // 原下标 3 的元素前移到下标 2
	EXPECT_EQ(GetElem(&list_, 3), 5);   // 原下标 4 的元素前移到下标 3
}

// ---------------------------------------------------------------------------
// 10. SqListDelete —— 删除头元素(下标 0)
// ---------------------------------------------------------------------------
TEST_F(SqListTest, Delete_AtHead) {
	PushSome(&list_, 3);                // [1, 2, 3]
	int removed = SqListDelete(&list_, 0);
	EXPECT_EQ(removed, 1);              // 返回头元素
	EXPECT_EQ(GetElem(&list_, 0), 2);   // 头元素变为原来的第二个元素
	EXPECT_EQ(SqListSize(&list_), 2);
}

// ---------------------------------------------------------------------------
// 11. SqListDelete —— 删除尾元素(下标 size-1)
// ---------------------------------------------------------------------------
TEST_F(SqListTest, Delete_AtTail) {
	PushSome(&list_, 3);                // [1, 2, 3]
	int removed = SqListDelete(&list_, 2);
	EXPECT_EQ(removed, 3);              // 返回尾元素
	EXPECT_EQ(SqListSize(&list_), 2);
}

// ---------------------------------------------------------------------------
// 12. GetElem —— 按下标取元素值(验证边界下标)
// ---------------------------------------------------------------------------
TEST_F(SqListTest, GetElem_ReturnsValueAtBoundary) {
	PushSome(&list_, 4);                // [1, 2, 3, 4]
	EXPECT_EQ(GetElem(&list_, 0), 1);   // 取下界(首元素)
	EXPECT_EQ(GetElem(&list_, 3), 4);   // 取上界(尾元素)
}

// ---------------------------------------------------------------------------
// 13. LocateElem —— 命中时返回第一个匹配元素的下标
// ---------------------------------------------------------------------------
TEST_F(SqListTest, LocateElem_ReturnsFirstMatchIndex) {
	SqListPushBack(&list_, 5);
	SqListPushBack(&list_, 9);
	SqListPushBack(&list_, 5);          // [5, 9, 5]
	EXPECT_EQ(LocateElem(&list_, 9), 1);    // 命中返回下标 1
	EXPECT_EQ(LocateElem(&list_, 5), 0);    // 有重复值时返回第一个下标 0
}

// ---------------------------------------------------------------------------
// 14. LocateElem —— 未命中时返回 -1
// ---------------------------------------------------------------------------
TEST_F(SqListTest, LocateElem_NotFoundReturnsMinusOne) {
	PushSome(&list_, 3);                // [1, 2, 3]
	EXPECT_EQ(LocateElem(&list_, 100), -1);  // 查不到约定返回 -1
}

// ---------------------------------------------------------------------------
// 15. SqListPopBack —— 尾删:只减少元素个数
// ---------------------------------------------------------------------------
TEST_F(SqListTest, PopBack_RemovesTail) {
	PushSome(&list_, 3);                // [1, 2, 3]
	SqListPopBack(&list_);
	EXPECT_EQ(SqListSize(&list_), 2);   // 个数减一
	EXPECT_EQ(GetElem(&list_, 1), 2);   // 新的尾部是原来的倒数第二个元素
}

// ---------------------------------------------------------------------------
// 16. SqListPopFront —— 头删:头部元素被移除,其余前移
// ---------------------------------------------------------------------------
TEST_F(SqListTest, PopFront_RemovesHead) {
	PushSome(&list_, 3);                // [1, 2, 3]
	SqListPopFront(&list_);
	EXPECT_EQ(SqListSize(&list_), 2);
	EXPECT_EQ(GetElem(&list_, 0), 2);   // 新的头部是原来的第二个元素
}

// ---------------------------------------------------------------------------
// 17. SqListPrint —— 冒烟测试:能正常完整打印,不崩溃
// ---------------------------------------------------------------------------
TEST_F(SqListTest, Print_DoesNotCrash) {
	PushSome(&list_, 3);
	SqListPrint(&list_);                // 打印 [1, 2, 3],只做冒烟验证
	EXPECT_TRUE(true);
}

// ---------------------------------------------------------------------------
// 18. SqListDestroy —— 销毁后应把资源全部置空/清零
// ---------------------------------------------------------------------------
TEST(SqListLifecycle, Destroy_ReleasesResources) {
	SqList s;
	SqListInit(&s);
	SqListPushBack(&s, 1);
	SqListDestroy(&s);
	EXPECT_EQ(s.arr, nullptr);   // 指针置空,避免悬空指针
	EXPECT_EQ(s.size, 0);        // 元素个数清零
	EXPECT_EQ(s.capacity, 0);    // 容量清零,后续若再用会重新分配
}

// ---------------------------------------------------------------------------
// 19~21. 死亡测试(EXPECT_DEATH):越界的非法调用应触发 assert 使进程退出
//
// 说明:GetElem / SqListDelete / SqListInsert 内部用 assert 保证"下标合法",
//        故对越界的调用,程序应当直接断言失败退出,而不是返回乱数据。
//        这类"接口保护"也属于接口行为的一部分,值得用死亡测试锁定。
// ---------------------------------------------------------------------------
#ifndef NDEBUG
TEST_F(SqListTest, GetElem_OutOfRangeCrashes) {
	// 空表上取下标 5:越界,应触发 assert 崩溃(死亡)
	EXPECT_DEATH(GetElem(&list_, 5), ".*");
}

TEST_F(SqListTest, Delete_OutOfRangeCrashes) {
	// 空表上删下标 0:越界,应触发 assert 崩溃(死亡)
	EXPECT_DEATH(SqListDelete(&list_, 0), ".*");
}

TEST_F(SqListTest, Insert_OutOfRangeCrashes) {
	PushSome(&list_, 2);                // [1, 2]
	// 下标 9 超过 size,非法插入,应触发 assert 崩溃(死亡)
	EXPECT_DEATH(SqListInsert(&list_, 9, 0), ".*");
}

#else
// Release (NDEBUG): assert is compiled out, so invalid indices are out of contract.
// Keep the same test names but skip instead of attempting dangerous calls.
TEST_F(SqListTest, GetElem_OutOfRangeCrashes) { /* assert disabled in Release: nothing to verify */ }

TEST_F(SqListTest, Delete_OutOfRangeCrashes) { /* assert disabled in Release: nothing to verify */ }

TEST_F(SqListTest, Insert_OutOfRangeCrashes) { /* assert disabled in Release: nothing to verify */ }

#endif

} // namespace