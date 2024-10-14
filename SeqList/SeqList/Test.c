#include "SeqList.h"

void Test1()//Œ≤≤ÂŒ≤…æ≤‚ ‘
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	//SLPushBack(&sl, 4);
	//SLPushBack(&sl, 5);
	//SLPushBack(&sl, 6);
	//SLPushBack(&sl, 7);
	//SLPushBack(&sl, 8);
	//SLPushBack(&sl, 9);
	SLPrintf(&sl);

	SLPopBack(&sl);
	SLPrintf(&sl);

	SLPopBack(&sl);
	SLPrintf(&sl);

	SLPopBack(&sl);
	SLPrintf(&sl);

	SLPopBack(&sl);
	SLPrintf(&sl);

	SLDestroy(&sl);
}
int main()
{
	Test1();
	return 0;
}