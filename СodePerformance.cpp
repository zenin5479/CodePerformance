#include <clocale>
#include <cstdio>

#include "lib.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	bool fla = true, flb = true, flc = true;
	int na = razmerrowvect();
	int ma = razmercolumnvect();
	int nb = razmerrowvect();
	int mb = razmercolumnvect();
	int nc = razmerrowvect();
	int mc = razmercolumnvect();

	double** a = new double* [na];
	FILE* fp_a = fopen("a.txt", "r");
	if (fp_a == nullptr)
	{
		printf("Ошибка при открытии файла для чтения\n");
		return 1;
	}

	vvod_vect(a, na, ma, fp_a);
	fclose(fp_a);

	double** b = new double* [nb];
	FILE* fp_b = fopen("b.txt", "r");
	if (fp_b == nullptr)
	{
		printf("Ошибка при открытии файла для чтения\n");
		delete[] a;
		return 1;
	}
	vvod_vect(b, nb, mb, fp_b);
	fclose(fp_b);

	double** c = new double* [nc];
	FILE* fp_c = fopen("c.txt", "r");
	if (fp_c == nullptr)
	{
		printf("Ошибка при открытии файла для чтения\n");
		delete[] a;
		delete[] b;
		return 1;
	}
	vvod_vect(c, nc, mc, fp_c);
	fclose(fp_c);

	int ia = 0, ja = 0;
	int ib = 0, jb = 0;
	int ic = 0, jc = 0;

	findPositiv(a, na, ma, fla, ia, ja);
	findPositiv(b, nb, mb, flb, ib, jb);
	findPositiv(c, nc, mc, flc, ic, jc);

	if (fla && flb && flc)
	{
		double Amin = findMinPositive(a, na, ma, ia, ja);
		double Bmin = findMinPositive(b, nb, mb, ib, jb);
		double Cmin = findMinPositive(c, nc, mc, ic, jc);
		double result = findRasnost(Amin, Bmin, Cmin);

		FILE* finish = fopen("finish.txt", "w");
		if (finish == nullptr)
		{
			printf("Ошибка при открытии файла для записи\n");
			delete[] a;
			delete[] b;
			delete[] c;
			return 1;
		}
		else
		{
			vivod(result, finish);
			fclose(finish);
		}
	}
	else
	{
		if (!fla)
		{
			printf("нет искомых в А\n");
		}
		else if (!flb)
		{
			printf("нет искомых в В\n");
		}
		else if (!flc)
		{
			printf("нет искомых в С\n");
		}
	}

	delet(a, na);
	delete[] a;
	delet(b, nb);
	delete[] b;
	delet(c, nc);
	delete[] c;

	return 0;
}