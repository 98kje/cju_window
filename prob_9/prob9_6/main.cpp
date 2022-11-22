#include <stdio.h>

typedef enum{ CYAN, MAGENTA, YELLOW = 5, BLACK} COLOR;

typedef enum{ UP, DOWN, LEFT, RIGHT} ARROW;

int main(void)
{
	COLOR my_color = YELLOW, c;
	ARROW direction = UP;
	
	int a = direction;

	for (int c = CYAN; c <= BLACK; c++)
	{
		a++;
		a = (a % 4);
		if (c == my_color) break;

	}

	switch (a)
	{
	case UP:
		printf("���� ����: ��"); break;
	case DOWN:
		printf("���� ����: �Ʒ�"); break;
	case LEFT:
		printf("���� ����: ����"); break;
	case RIGHT:
		printf("���� ����: ������"); break;


	}
	return 0;
}