#include <stdio.h>

struct marriage
{
	char name[20];
	int age;
	char sex;
	double height;
};

void print_data(marriage* mp);

int main(void)
{
	struct marriage m1 = { "Andy", 22, 'm', 187.5 };
	
	print_data(&m1);
	
	return 0;
	
}

void print_data(marriage* mp)
{
	printf("name : %s\n", mp->name);
	printf("age: %d\n", mp->age);
	printf("sex: %c\n", mp->sex);
	printf("height: %lf\n", mp->height);
}
