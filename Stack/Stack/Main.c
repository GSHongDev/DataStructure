#include "Stack.h"
// 测试用例函数
void testStack() 
{
    ST st;
    // 初始化栈
    STInit(&st);

    // 测试栈是否为空
    assert(STEmpty(&st) == true);

    // 入栈操作
    STPush(&st, 1);
    STPush(&st, 2);
    STPush(&st, 3);

    // 测试栈的大小
    assert(STSize(&st) == 3);

    // 测试栈顶元素
    assert(STTop(&st) == 3);

    // 出栈操作
    STPop(&st);
    assert(STSize(&st) == 2);
    assert(STTop(&st) == 2);

    // 再次出栈
    STPop(&st);
    assert(STSize(&st) == 1);
    assert(STTop(&st) == 1);

    // 再次出栈
    STPop(&st);
    assert(STSize(&st) == 0);
    assert(STEmpty(&st) == true);

    // 销毁栈
    STDestroy(&st);
}

int main()
{
    testStack();
    printf("Stack Test Passed!\n");
	return 0;
}