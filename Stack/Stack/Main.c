#include "Stack.h"

void Test1()
{
	ST S;
	STInit(&S);
	STPush(&S, 1);
	STPrint(S);
	STPush(&S, 2);
	STPrint(S);
	STPush(&S, 3);
	STPush(&S, 4);
	STPrint(S);
	STPop(&S);
	STPrint(S);
	STPush(&S, 5);

	STDestroy(&S);
}
int main()
{
	Test1();
	return 0;
}