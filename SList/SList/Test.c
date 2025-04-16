#include "SList.h"
#include "TestSLT.h"

int main() {
    SLNode* phead = NULL;

    // 依次执行各个测试用例
    testSLTPushBack(&phead);
    testSLTPushFront(&phead);
    testSLTPopFront(&phead);
    testSLTPopBack(&phead);
    testSLTFind(phead);
    testSLTInsert(&phead);
    testSLTErase(&phead);
    testLTEmpty(phead);
    testLTSize(phead);
    testSLTReverseList(&phead);
    testSLTDestroy(&phead);

    return 0;
}
