#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int* Insert(int,int, int*);
int FindDigit(int);
int main()
{
	int num;
	scanf_s("%d", &num, sizeof(num));
	printf("hello, world! %d\n", num);
	int right;
	//int ans = num /= 2;
	//int a = num * 2 - 4;
	int count = 1;
	int** totArr = (int**)malloc(sizeof(int*) * num);
	for (int i = 0; i<num; i++)
	{
		totArr[i] = (int)malloc(sizeof(int) * num);
	}
	for (int i = 0; i < num; i++)
	{
		if (i < num / 2+1)
		{
			totArr[i] = Insert(num, i, &count);
		}
		else
		{
			totArr[i] = Insert(num, num - i - 1, &count);
		}
		printf("\n");
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			int maxLength = FindDigit(count)+1;
			if (totArr[j][i] == -1)
			{
				for(int l = 0; l<maxLength; l++)
					printf(" ");
			}
			else
			{
				char* tempStr = (char*)malloc(sizeof(char) * maxLength);
				sprintf(tempStr, "%d ", totArr[j][i]);
				for (; strlen(tempStr) < maxLength;)strcat(tempStr," ");
				printf("%s", tempStr);
				
			}
		}
		printf("\n");
	}
	return 1;
}

int* Insert(int max, int curser, int* val)
{
	int* arr = malloc(sizeof(int)*max);
	for (int u = 0; u < curser; u++)
	{
		arr[u] = -1;
	}
	for (int j = curser; j < max - curser; j++)
	{
		//printf("%d", *val);
		arr[j] = *val;
		*val += 1;
	}
	for (int y = max - curser; y < max; y++)
	{
		arr[y] = -1;
		//printf("_");
	}
	return arr;
}

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
