#include "lib.h"
#include <cstdio>

int razmerrowvect()
{
	int n;
	do
	{
		printf("%s", "¬ведите количество строк массива \n");
		scanf("%d", &n);
		if (n <= 0 || n >= 20)
		{
			printf("%s", "¬ведено не верное значение\n");
		}
	} while (n <= 0 || n >= 20);

	return n;
}

int razmercolumnvect()
{
	int m;
	do
	{
		printf("%s", "¬ведите количество столбцов массива \n");
		scanf("%d", &m);
		if (m <= 0 || m >= 20)
		{
			printf("%s", "¬ведено не верное значение\n");
		}
	} while (m <= 0 || m >= 20);

	return m;
}

void vvod_vect(double**& x, int n, int m, FILE* f)
{
	for (int i = 0; i < n; i++)
	{
		x[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			fscanf(f, "%lf", &x[i][j]);
			printf("%lf ", x[i][j]);
		}
		printf("%s", "\n");
	}
}

int findPositiv(double** x, int n, int m, bool& fl, int& istart, int& jstart)
{
	istart = -1;
	int j = 0;
	int i = 0;
	while (i < n and fl)
	{
		i++;
		int j = 0;
		while (j < m and fl)
		{
			if (x[i][j] > 0)
			{
				fl = false;
			}
			else
			{
				j++;
			}
		}
	}
	istart = i;
	jstart = j;
	return istart, jstart;

	fl = false;
}

double findMinPositive(double** x, int n, int m, int& istart, int& jstart)
{
	double min = x[istart][jstart];

	for (int i = istart + 1; i < n; i++)
	{
		for (int j = jstart + 1; j < m; j++)
		{
			if (x[i][j] > 0 && x[i][j] < min)
			{
				min = x[i][j];
			}
		}
	}

	return min;
}

double findRasnost(double min1, double min2, double min3)
{
	return min1 * min2 - min3;
}

void vivod(double result, FILE* f)
{
	fprintf(f, "–езультат: %lf\n", result);
}

void delet(double**& x, int n)
{
	for (int i = 0; i < n; i++)
		delete[] x[i];
}