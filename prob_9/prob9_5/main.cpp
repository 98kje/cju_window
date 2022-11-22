#include <stdio.h>
#include <stdlib.h>

typedef struct train Train;

struct train                    //1
{
	int seats;
	struct train *next;         //1과 형태가 같음 (자기참조구조체)
};

int main(void)
{
	Train* head = NULL, * tail = NULL;
	for (int i = 0; i < 5; i++)
	{
		if (head == NULL)
		{
			head = tail = (Train *)malloc(sizeof(Train));
		}
		else
		{
			tail-> next = (Train*)malloc(sizeof(Train));
			tail = tail-> next;
		}
	}
	return 0;
}