// lab5.1_0.cpp: определяет точку входа для консольного приложения.
//
/*2. По  заданной перестановке из N элементов выдать K сле-
дующих перестановок в лексикографическом порядке.*/
#include "stdafx.h"

void next_Permutations();
int next_p(int *, int );

int main()
{
	//Подключаем русский язык
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char i = ' ';
	while (i != '2')
	{
		printf_s("\n**************************");
		printf("\nВыберите действие:\n1 По заданной перестановке из N элементов выдать K следующих перестановок в лексикографическом порядке.\n2 Завершить сеанс\n");
		printf_s("Укажите код выбранного действия: ");
		i = _getche();
		switch (i)
		{
		case '1':
			next_Permutations();
			break;
		case '2':
			exit(0);
		default:
			printf_s("\nВведен неверный код действия\n");
			break;
		}
	}
    return 0;
}

void next_Permutations()
{
	char *str;
	str = (char*)malloc(50);
	char *s, *ss;
	const char *ct = " ";
	int p[20];
	printf_s("\nВведите перестановку: ");
	fseek(stdin, 0, SEEK_SET);
	fgets(str,50,stdin);
	s = strtok_s(str, ct, &ss);	
	int n = 0;
	while (s != NULL)
	{
		p[n] = atoi(s);
		n++;
		s = strtok_s(NULL, ct, &ss);
	}
	free(str);
	int k = 0;
	printf_s("Введите K: ");
	scanf_s("%d", &k);
	while (k != 0)
	{
		if (next_p(p, n) == -1)
		{
			printf_s("выдана последняя наибольшая перестановка\n");
			break;
		}
		else
		{
			k--;
			for (int i = 0; i < n; i++)
			{
				printf_s("%d ", p[i]);

			}
			printf_s("\n");
		}
	}
	
}

int next_p(int *p, int n)
{
	int i = n-2;
	while (i>=0)
	{
		if (*(p+i)<*(p+i + 1))
		{
			break;
		}
		i--;
	}
	if (i == -1)
	{
		return -1;
	}
	int j = i + 1;
	int max = j;	
	while (j<n)
	{
		if ((*(p+j) > *(p+i)) && (*(p+j) <= *(p+ max)))
		{
			max = j;
		}
		j++;
	}
	int t = *(p + i);
	*(p + i) = *(p + max);
	*(p + max) = t;
	
	for (int k = 1; k < (n-1-i)/2+1; k++)
	{
		t = *(p + i+k);
		*(p +i+ k) = *(p+n-k);
		*(p+n-k) = t;
	}
	return 0;

}