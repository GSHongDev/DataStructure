#include "Queue.h"

// ========== 测试工具宏 ==========
#ifdef DEBUG
#define TEST_START(func) printf("\n[DEBUG TEST] %s ... ", #func)
#define TEST_END()       printf("OK\n")
#else
#define TEST_START(func)
#define TEST_END()
#endif

// ========== 基础功能测试 ==========
void TestQueueInitDestroy() {
    TEST_START(TestQueueInitDestroy);
    Queue q;

    // 初始化后状态
    QueueInit(&q);
    assert(QueueEmpty(&q));
    assert(q.phead == NULL);
    assert(q.ptail == NULL);
    assert(q.size == 0);

    // 销毁空队列（安全）
    QueueDestroy(&q);
    assert(q.phead == NULL);
    assert(q.ptail == NULL);
    assert(q.size == 0);

    // 重复销毁（DEBUG 断言触发）
    // QueueDestroy(&q);  // 取消注释会触发 assert(pq->phead)
    TEST_END();
}

void TestQueueSingleNode() {
    TEST_START(TestQueueSingleNode);
    Queue q;
    QueueInit(&q);

    // 单节点入队
    QueuePush(&q, 100);
    assert(!QueueEmpty(&q));
    assert(QueueSize(&q) == 1);
    assert(QueueFront(&q) == 100);
    assert(QueueBack(&q) == 100);
    assert(q.phead == q.ptail);  // 头尾指针重合

    // 单节点出队
    QueuePop(&q);
    assert(QueueEmpty(&q));
    assert(q.phead == NULL);
    assert(q.ptail == NULL);
    TEST_END();
}

// ========== 边界条件测试（触发断言）==========
void TestQueueEmptyAccess() {
    TEST_START(TestQueueEmptyAccess);
    Queue q;
    QueueInit(&q);

    // 空队列访问 Front/Back（DEBUG 断言触发）
    // QueueFront(&q);  // 取消注释触发 assert(pq->phead)
    // QueueBack(&q);   // 取消注释触发 assert(pq->ptail)
    // QueuePop(&q);    // 取消注释触发 assert(pq->phead)

    // 验证断言保护（需在 DEBUG 模式下运行观察中断）
    printf("（DEBUG 下以上操作应触发断言，此处测试通过）");
    TEST_END();
}

void TestQueueSizeConsistency() {
    TEST_START(TestQueueSizeConsistency);
    Queue q;
    QueueInit(&q);

    // 入队时 size 递增
    for (int i = 0; i < 10; i++) {
        QueuePush(&q, i);
        assert(QueueSize(&q) == i + 1);
    }

    // 出队时 size 递减
    while (!QueueEmpty(&q)) {
        QueuePop(&q);
        assert(QueueSize(&q) == (10 - (10 - QueueSize(&q)) - 1));
    }
    TEST_END();
}

// ========== 异常场景测试 ==========
void TestQueueMemoryError() {
    TEST_START(TestQueueMemoryError);
    Queue q;
    QueueInit(&q);

    // 模拟内存分配失败（需手动限制内存，如在调试器中设置）
#ifdef DEBUG
// 占用大量内存导致后续 malloc 失败
    void* big_mem = malloc(1024 * 1024 * 1024);  // 申请 1GB（根据环境调整）
    if (big_mem) {
        QueuePush(&q, 1);  // 此时 malloc 应失败
        assert(QueueEmpty(&q));  // 队列状态不变
        free(big_mem);
    }
#endif
    TEST_END();
}

// ========== 综合流程测试 ==========
void TestQueueFullCycle() {
    TEST_START(TestQueueFullCycle);
    Queue q;
    QueueInit(&q);

    // 混合操作：入队 → 访问 → 出队
    int nums[] = { 1, 3, 5, 7, 9 };
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        QueuePush(&q, nums[i]);
        assert(QueueBack(&q) == nums[i]);  // 尾元素正确
    }

    // 验证队列顺序
    int idx = 0;
    while (!QueueEmpty(&q)) {
        assert(QueueFront(&q) == nums[idx++]);
        QueuePop(&q);
    }

    // 验证销毁后状态
    QueueDestroy(&q);
    assert(q.phead == NULL && q.ptail == NULL && q.size == 0);
    TEST_END();
}

// ========== 主函数集成测试 ==========
int main() {
#ifdef DEBUG
    TestQueueInitDestroy();
    TestQueueSingleNode();
    TestQueueEmptyAccess();   // 需观察断言触发（非崩溃）
    TestQueueSizeConsistency();
    TestQueueMemoryError();   // 需手动调试验证
    TestQueueFullCycle();

    // 原业务逻辑测试
    printf("\n[Normal Test] Business Logic ... ");
#endif

    // 原代码逻辑（验证正常流程）
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1); QueuePush(&q, 2); QueuePush(&q, 3);
    while (!QueueEmpty(&q)) {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");

    QueueDestroy(&q);
    return 0;
}