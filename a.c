#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ver_ijk(unsigned int * A, unsigned int * B, unsigned int * C, int n)
{
	int i, j, k;
	double sum;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			sum = 0.0;
			for (k = 0; k < n; k++)
				sum += A[i * n + k] * B[k * n + j];
			C[i * n + j] += sum;
		}
}
void ver_jik(unsigned int * A, unsigned int * B, unsigned int * C, int n)
{
	int i, j, k;
	double sum;
	for (j = 0; j < n; j++)
		for (i = 0; i < n; i++) {
			sum = 0.0;
			for (k = 0; k < n; k++)
				sum += A[i * n + k] * B[k * n + j];
			C[i * n + j] += sum;
		}
}
void ver_ikj(unsigned int * A, unsigned int * B, unsigned int * C, int n)
{
	int i, j, k;
	double temp;
	for (i = 0; i < n; i++)
		for (k = 0; k < n; k++) {
			temp = A[i * n + k];
			for (j = 0; j < n; j++)
				C[i * n + j] += temp * B[k * n + j];
		}
}
void ver_kij(unsigned int * A, unsigned int * B, unsigned int * C, int n)
{
	int i, j, k;
	double temp;
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++) {
			temp = A[i * n + k];
			for (j = 0; j < n; j++)
				C[i * n + j] += temp * B[k * n + j];
		}
}

void ver_kji(unsigned int * A, unsigned int * B, unsigned int * C, int n)
{
	int i, j, k;
	double temp;
	for (k = 0; k < n; k++)
		for (j = 0; j < n; j++) {
			temp = B[k * n + j];
			for (i = 0; i < n; i++)
				C[i * n + j] += A[i * n + k] * temp;
		}
}
void ver_jki(unsigned int * A, unsigned int * B, unsigned int * C, int n)
{
	int i, j, k;
	double temp;
	for (j = 0; j < n; j++)
		for (k = 0; k < n; k++) {
			temp = B[k * n + j];
			for (i = 0; i < n; i++)
				C[i * n + j] += A[i * n + k] * temp;
		}
}


int main(int argv, char* argc[]) {

	if (argv != 3) {
		printf("<version> <matrix_size>\n");
		printf("First parameter is version. For example - \"ver_ijk\" with 6 different permutation of i,j,k. \n");
		printf("Second parameter is n where n is size of the matrix (n x n)\n");
		return 1;
	}


	char* a = argc[1];
	unsigned int n = atoi(argc[2]);

	if (n <= 0) {
		printf("Please enter valid n number between 1 and 10,000\n");
		return 1;
	}

	unsigned int* A = malloc(((unsigned long long)n*n )* sizeof(int));
	unsigned int* B = malloc(((unsigned long long)n * n) * sizeof(int));
	unsigned int* C = malloc(((unsigned long long)n * n) * sizeof(int));

	if (A == NULL || B == NULL || C == NULL) {
		printf("Memory allocation has failed.\n");
		return 1;
	}

	if (strcmp(a, "ver_ijk") == 0)
	{ ver_ijk(A, B, C, n);}

	else if(strcmp(a, "ver_jik") == 0)
	{ ver_jik(A, B, C, n); }

	else if (strcmp(a, "ver_ikj") == 0)
	{	ver_ikj(A, B, C, n);}

	else if (strcmp(a, "ver_kij") == 0)
	{	ver_kij(A, B, C, n);}

	else if (strcmp(a, "ver_kji") == 0)
	{	ver_kji(A, B, C, n);}

	else if (strcmp(a, "ver_jki") == 0)
	{ ver_jki(A, B, C, n);}

	else {
		printf("Please provide the version as the first parameter and correctly. Like - \"ver_ijk\" with 6 different permutation of ijk.");
		return -1;
	}

	free(A);
	free(B);
	free(C);
	return 0;
}
