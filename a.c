#include <stdio.h>
#include <stdlib.h>


void ver_ijk(unsigned int ** A, unsigned int ** B, unsigned int ** C, int n)
{
	int i, j, k;
	double sum;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			sum = 0.0;
			for (k = 0; k < n; k++)
				sum += A[i][k] * B[k][j];
			C[i][j] += sum;
		}
}
void ver_jik(unsigned int ** A, unsigned int ** B, unsigned int ** C, int n)
{
	int i, j, k;
	double sum;
	for (j = 0; j < n; j++)
		for (i = 0; i < n; i++) {
			sum = 0.0;
			for (k = 0; k < n; k++)
				sum += A[i][k] * B[k][j];
			C[i][j] += sum;
		}
}
void ver_ikj(unsigned int ** A, unsigned int ** B, unsigned int ** C, int n)
{
	int i, j, k;
	double temp;
	for (i = 0; i < n; i++)
		for (k = 0; k < n; k++) {
			temp = A[i][k];
			for (j = 0; j < n; j++)
				C[i][j] += temp * B[k][j];
		}
}
void ver_kij(unsigned int ** A, unsigned int ** B, unsigned int ** C, int n)
{
	int i, j, k;
	double temp;
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++) {
			temp = A[i][k];
			for (j = 0; j < n; j++)
				C[i][j] += temp * B[k][j];
		}
}

void ver_kji(unsigned int ** A, unsigned int ** B, unsigned int ** C, int n)
{
	int i, j, k;
	double temp;
	for (k = 0; k < n; k++)
		for (j = 0; j < n; j++) {
			temp = B[k][j];
			for (i = 0; i < n; i++)
				C[i][j] += A[i][k] * temp;
		}
}
void ver_jki(unsigned int ** A, unsigned int ** B, unsigned int ** C, int n)
{
	int i, j, k;
	double temp;
	for (j = 0; j < n; j++)
		for (k = 0; k < n; k++) {
			temp = B[k][j];
			for (i = 0; i < n; i++)
				C[i][j] += A[i][k] * temp;
		}
}


int main(int argv, char* argc[]) {

	if (argv != 3) {
		printf("First parameter is version. For example - \"ver_ijk\" with 6 different permutation of i,j,k. \n");
		printf("Second parameter is n where n is size of the matrix (n x n)\n");
		return 1;
	}


	char* a = argc[1];
	unsigned int n = argc[2];
	unsigned int** A = malloc(((unsigned long long)n*n )* sizeof(int*));
	unsigned int** B = malloc(((unsigned long long)n * n) * sizeof(int*));
	unsigned int** C = malloc(((unsigned long long)n * n) * sizeof(int*));

	if (argc[1] == "ver_ijk")
	{ ver_ijk(A, B, C, n);}

	else if(argc[1] == "ver_jik") 
	{ ver_jik(A, B, C, n); }

	else if (argc[1] == "ver_ikj")
	{	ver_ikj(A, B, C, n);}

	else if (argc[1] == "ver_kij")
	{	ver_kij(A, B, C, n);}

	else if (argc[1] == "ver_kji")
	{	ver_kji(A, B, C, n);}

	else if (argc[1] == "ver_jki")
	{ ver_jki(A, B, C, n);}

	else {
		printf("Please provide the version as first parameter and correctly. Like - \"ver_ijk\" with 6 different permutation of ijk.");
		return -1;
	}

	free(A);
	free(B);
	free(C);
	return 0;
}