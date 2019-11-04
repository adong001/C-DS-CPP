#include"stack.h"
#include"dequeue.h"
int main()
{
	Dequeue test;
	dequeueInit(&test);


	dequeuePush(&test, 1);
	dequeuePush(&test, 2);
	dequeuePush(&test, 3);
	dequeuePush(&test, 4);
	dequeuePush(&test, 5);
	printf("%d\n", dequeueFront(&test));
	dequeuePop(&test);
	printf("%d\n", dequeueFront(&test));
	dequeuePop(&test);
	printf("%d\n", dequeueFront(&test));
	dequeuePop(&test);
	printf("%d\n", dequeueFront(&test));
	/*printf("%d\n", dequeuePush(&test, 1));
	printf("%d\n", dequeuePush(&test, 2));
	printf("%d\n", dequeuePush(&test, 3));
	printf("%d\n", dequeuePush(&test, 4));
	printf("%d\n", dequeuePush(&test, 5));*/
    system("pause");
    return 0;
}