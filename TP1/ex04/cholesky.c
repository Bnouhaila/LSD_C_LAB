#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10

int main()
{
	float A[N][N], B[N],X[N];
	float C[N][N];
	int i,j,k,n;
	float s1,s2;
	//the size of the matrix//
	printf("donner la dimension de la matrice:");
	scanf("%d",&n);
	//filling the matrix A//
	printf("Filling the matrix A\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("A[%d][%d]=",i,j);
			scanf("%f",&A[i][j]);
		}
	}
	//filling the vector B//
	printf("Filling the matrix B\n");
	for(i=0; i<n; i++)
	{
		printf("B[%d]=",i);
		scanf("%f", &B[i]);
	}

	//cholesky//
	C[0][0]=sqrt(A[0][0]);
	for(i=1; i<n; i++)
	{
		C[i][0]=A[i][0]/C[0][0];
	}
	for(j=1; j<n; j++)
	{
		for(i=0;i<j-1; i++)
		{
			C[i][j]=0;
		}
	for(k=0; k<j; k++)
	{
		s1=s1+pow(C[j][k],2);
	}
        
	C[j][j]=sqrt(A[j][j]-s1);
	for(i=j+1;i<n;i++)
	{
		for(k=0; k<j; k++)
		{
			s2=s2+C[j][k]*C[j][k];
		}
		C[i][j]=(1/C[j][j])*(A[i][j]-s2);
	}

	}
	for(i=0;i<n;i++)
	{
		for(j=0; j<n; j++)
			printf("%f\n", C[i][j]);
	}
		
  return (0);
}
