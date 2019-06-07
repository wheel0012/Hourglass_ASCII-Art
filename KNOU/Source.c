#include <stdio.h>
#include<stdlib.h>
const int size = 100;
void main()
{
	while (1)
	{
		char a[20] = {0x0d,};
		scanf_s("%s", a, sizeof(a)*20);
		for (int i = 0; i < size; i++)
		{
			if (a[i] == 0x00) break;
			else if (a[i] >= 97&&a[i] <= 122)a[i] -= 32;
			else if(a[i]>=65 && a[i] <= 97) a[i]+= 32;
		}
		for (int j = 19; j >= 0; j--)
		{
			if (a[j] < 1)continue;
			else printf("%c", a[j]);
		}
		printf("\n");
	}
}