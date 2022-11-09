#include <stdio.h>
#include <string.h>

void add_by_pointer(int* pa, int* pb, int* pr)
{
	*pr = *pa + *pb;  // This is the answer to the blank.
}
int main(void)
{
	int a = 10, b = 20, res = 0;
	add_by_pointer(&a, &b, &res);
	printf("%d", res);
	return 0;
}