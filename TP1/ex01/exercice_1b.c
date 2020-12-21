#include <stdio.h>
#include <stdlib.h>
#define N 10

float *remontee(float A[N][N], float B[N], int n)
{
	float *X;
	X=malloc(sizeof(float) * n);
	int i ;
	int j;
	float s;
	X[N-1] = B[N-1] / A[N][N];
	for(i = n-2; i>0 ; i--)
	{
		s = 0;
		for(j=i+1; j<n-1; j++)
		{
			s=s+A[i][j]*X[j];
		}
	X[i] = (B[i] - s)/A[i][i];
	}
  return X;
}

int main()
{
  float   A[N][N], B[N];
  float   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the vector B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = remontee(A, B, n);

  /* Printing the results */
  printf("\nsolution: ");
  for (int i = 0; i < n; i++)
    printf("%f\n", x[i]);
}

