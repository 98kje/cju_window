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
		printf("현재 방향: 위"); break;
	case DOWN:
		printf("현재 방향: 아래"); break;
	case LEFT:
		printf("현재 방향: 왼쪽"); break;
	case RIGHT:
		printf("현재 방향: 오른쪽"); break;


	}
	return 0;
}