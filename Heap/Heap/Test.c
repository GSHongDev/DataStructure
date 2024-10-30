#include "Heap.h"

////第一版：手动创堆
//int main()
//{
//	int a[] = { 4,6,2,1,5,8,2,9 };
//	HP hp;
//	HeapInit(&hp);
//
//	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
//	{
//		HeapPush(&hp,a[i]);
//	}
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	printf("\n");
//	HeapDestroy(&hp);
//	return 0;
//}


//在数组这个结构直接动手
int main ()
{
	int a[] = { 4,6,2,1,5,8,2,9 };

	HP hp;
	HeapInit(&hp);



	HeapDestroy(&hp);
	return 0;
}