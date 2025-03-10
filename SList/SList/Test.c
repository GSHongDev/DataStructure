#include "SList.h"


void TEST1()
{
	//≤‚ ‘Œ≤≤Â
	SLNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);

}

void TEST2()
{
	//≤‚ ‘Õ∑≤Â
	SLNode* plist = NULL;

	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 5);
	SLTPushFront(&plist, 6);
	SLTPrint(plist);
}

int main()
{


	TEST2();
	return 0;
}