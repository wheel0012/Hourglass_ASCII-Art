//stdio.h 헤더파일 포함
#include<stdio.h>
//string.h 헤더파일 포함
#include<string.h>
//모래시계를 만들기 위해 1차원 배열 구축하는 함수 정의
int* Insert(int,int, int*);
//자릿수 알아내는 함수 정의
int FindDigit(int);
//과제 1번 대소문자 변환 함수 정의
void change_ltj(void);
//과제 2번 모래시계 출력 함수 정의
void draw_ltj(void);
//main 함수 구현
int main(void)
//main 함수 블록 시작
{
	//change_ltj 함수 호출
	change_ltj();
	//draw_ltj 함수 호출
	draw_ltj();
//main 함수 블록 끝
}
//Insert 함수 구현
int* Insert(int max, int curser, int* val)
//Insert 함수 블록 시작
{
	//반환할 1차원 int 배열 정의
	int* arr = malloc(sizeof(int)*max);
	//수열 위쪽 공백 입력 
	for (int u = 0; u < curser; u++)
	//for문 블록 시작
	{
		//공백 처리할 식별자 입력
		arr[u] = -1;
	//for문 블록 끝
	}
	//수열 입력
	for (int j = curser; j < max - curser; j++)
	//for문 블록 시작
	{
		//수 입력
		arr[j] = *val;
		//수 증가
		*val += 1;
	//for문 블록 끝
	}
	//수열 아래쪽 공백 입력
	for (int y = max - curser; y < max; y++)
	//for문 블록 시작
	{
		//공백 처리할 식별자 입력
		arr[y] = -1;
	//for문 블록 끝
	}
	//모래시계의 한 줄 반환
	return arr;
//Insert 함수 블록 끝
}
//자릿수 함수 시작
int FindDigit(int value)
{
	int count = 0;
	while (value >= 1)
	{
		value /= 10;
		count++;
	}
	return count;
}
void change_ltj(void)
{
	const int size = 100;
	char a[100] = { 0, };
	char* intro = "Enter string : ";
	printf("%s", intro);
	gets(a);
	for (int i = 0; i < size; i++)
	{
		if (a[i] >= 97 && a[i] <= 122)a[i] -= 32;
		else if (a[i] >= 65 && a[i] <= 97) a[i] += 32;
	}
	printf("Output ==> ");
	for (int j = size - 2; j >= 0; j--)
	{
		if (a[j] != 0)
			printf("%c", a[j]);
	}
	printf("\n");
	puts("-----------------------------------------------");
}
void draw_ltj(void)
{
	while (1)
	{
		int num;
		printf("Enter number : ");
		scanf_s("%d", &num, sizeof(num));
		if (num == 0)
		{
			printf("Close program. Name : LeeTaeJun");
			return;
		}
		else if(!(num % 2))
		{
			printf("Enter odd number. Student ID:201934-154081\n");
			continue;
		}
		int right;
		//int ans = num /= 2;
		//int a = num * 2 - 4;
		int count = 1;
		int** totArr = (int**)malloc(sizeof(int*) * num);
		for (int i = 0; i < num; i++)
		{
			totArr[i] = (int)malloc(sizeof(int) * num);
		}
		for (int i = 0; i < num; i++)
		{
			if (i < num / 2 + 1)
			{
				totArr[i] = Insert(num, i, &count);
			}
			else
			{
				totArr[i] = Insert(num, num - i - 1, &count);
			}
		}
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				int maxLength = FindDigit(count) + 1;
				if (totArr[j][i] == -1)
				{
					for (int l = 0; l < maxLength; l++)
						printf(" ");
				}
				else
				{
					char* tempStr = (char*)malloc(sizeof(char) * maxLength);
					sprintf_s(tempStr, sizeof(tempStr), "%d ", totArr[j][i]);
					for (; strlen(tempStr) < maxLength;)strcat_s(tempStr, sizeof(tempStr), " ");
					printf("%s", tempStr);

				}
			}
			printf("\n");
		}
	}
}