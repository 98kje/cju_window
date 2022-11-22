#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUNUM 5

typedef struct
{
	int studentID;
	char name[100];
	int kor, eng, mat;
	int tscore;
	double average;
	char grade;
} Student_data;

void input_data(Student_data* pary);
void calc_data(Student_data* pary);
void sort_data(Student_data* pary);
void print_data(Student_data* pary);

int main(void)
{
	Student_data arry[STUNUM];          // ㅁㅁㅁㅁㅁ arry[5]
	input_data(arry);
	calc_data(arry);

	printf("# 정렬 전 데이터 ............\n\n");
	print_data(arry);
	sort_data(arry); //내림차순
	
	printf("\n\n# 정렬 후 데이터 ............\n\n");
	print_data(arry);

	return 0;
}

void input_data(Student_data* pary)
{
	for (int i = 0; i < STUNUM; i++)
	{
		printf(" Enter the StudentID : ");
		scanf_s("%d", &pary->studentID);
		printf(" Enter the Name : ");
		scanf_s("%s", pary->name,20);  
		printf(" Enter the Kor,Eng,Mat score : ");
		scanf_s("%d%d%d", &pary->kor, &pary->eng, &pary->mat);
		pary = pary + 1;

	}
}

void calc_data(Student_data* pary)
{
	for (int i = 0; i < STUNUM; i++)
	{
		pary->tscore = pary->kor + pary->eng + pary->mat;
		pary->average = pary->tscore / 3.0;
		if (pary->average >= 90.0)
		{
			pary->grade = 'A';
		}
		else if (pary->average >= 80.0)
		{
			pary->grade = 'B';
		}
		else if (pary->average >= 70)
		{
			pary->grade = 'C';
		}
		else if (pary->average < 70)
		{
			pary->grade = 'F';
		}
		pary = pary + 1;
	}
}

void sort_data(Student_data* pary) //don't only tscore change
{
	Student_data temp;
	int i, j;
	int hightscore;

	for (i = 0; i < 4; i++) 
	{
		hightscore = i;
		for (j = i + 1; j < 5; j++) {
			if (pary[hightscore].tscore < pary[j].tscore)
			{
				hightscore = j;
			}
		}

		if (hightscore != i)
		{
			temp = pary[hightscore];
			pary[hightscore] = pary[i];  // return hightscore -> i
			pary[i] = temp;
		}
	}

			
	
}
	


void print_data(Student_data* pary)
{
	for (int i = 0; i < STUNUM; i++)
	{
		printf("%5d %7s %5d %5d %5d %5d %7.1lf %5c\n", pary->studentID, pary->name, pary->kor, pary->eng, pary->mat, pary->tscore, pary->average, pary->grade);
		pary = pary + 1;
	}
}
