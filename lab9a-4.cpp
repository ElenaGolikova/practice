#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
void input(int **a, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)  {
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}
void output(int **a, int n){
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
		{
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
}
int max(int **a, int n){
	int i, j, sum, k, maxsum=0;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j<n; j++)  {
			sum = sum + a[i][j];
		}
		if (sum>maxsum) {
			maxsum = sum;
			k = i;
		}
	}
	printf("Наибольшая сумма элементов строки: %d \n", maxsum);
	return (k);
}
void convert(int **a, int n, int k){
	int i, j;
	for (i = 0; i < n; i++){
		if (i == k){
			continue;
		}
		for (j = 0; j < n; j++)
		{
			a[i][j] = a[k][j];
		}
	}
}
int main()
{
	setlocale(LC_ALL, "");
	int **a;
	int i, n, k;
	printf("Введите размерность массива: ");
	scanf("%d", &n);
	a = new int *[n];
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	input(a, n);
	printf("Исходный массив:\n");
	output(a, n);
	k = 0;
	k=max(a, n);
	convert(a, n, k);
	printf("Результат работы программы:\n");
	output(a, n);
	for (i = 0; i < n; i++)
		free(a[i]);
	free(a);
	getchar();
}
