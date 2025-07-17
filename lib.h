#include <iostream>
#include <cstdio>

int razmerrowvect();
int razmercolumnvect();
void vvod_vect(double**& x, int n, int m, FILE* f);
void vvod_vect(double*& x, int n, FILE* f);
double findMinPositive(double** x, int n, int m, int& istart, int& jstart);
double findRasnost(double min1, double min2, double min3);
void vivod(double result, FILE* f);
int findPositiv(double** x, int n, int m, bool& fl, int& istart, int& jstart);
void delet(double**& x, int n);