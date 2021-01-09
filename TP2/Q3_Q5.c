#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double f(double t)
{
	return (exp(-pow(t,2)/2));
}

double rectangledr(double (*f)(double),double a, double b, int n)
{
	double h=(b-a)/n;
	double I=0;
	double x=a;
	for (int i=0; i<n; i++)
	{
		I+=f(x);
		x+=h;
	}
	return (h*I);
}
double rectanglegch(double (*f)(double), double a, double b, int n)
{
	double h = (b - a)/n;
	double I=0;
	double x=a+h;
	for(int i=0; i<= n - 1; i++)
	{
		I+=f(x);
		x+=h;
	}
	return(h*I);
}
double trap(double(*f)(double x), double a,double b, int n)
{
	double h=(b-a)/n;
	double I=0.5 * (f(a)+f(b));
	double x=a+h;
	for(int i=0;i<n-1;i++)
	{
		I+=f(x);
		x=x+h;
	}
	return h*I;
}
double simpson(double (*f)(double), double a, double b, int n)
{
	double h = (b-a)/n;
	double x=a+h;
	double z=a+h/2;
	double I1=0;
	double I2=f(z);
	for(int i = 0; i<n-1; i++)
	{
		z+=h;
		I1+=f(x);
		I2+=f(z);
		x+=h;
	}
	return (h/6)*(f(a)+f(b)+2*I1+4*I2);
}
// question3
double nombernecessaire(double(*f)(double), int a, int b, double(*methode)(double(*)(double),double,double,int),double err)
{
	double I=0.855624391892149;
	double n=1;
	while (fabs(methode(f,a,b,n) - I)> err)
	{
		n++;
	}
	return n;
}
// question5
double romberg(double (*f)(double),int a, int b, double err, int nmax)
{
	double R[nmax][nmax];
	int N;
	int i,k;
	for( i=0; i<nmax;i++)
	{
		N=pow(2,i);
		R[i][0]=trap(f,a,b,N);
		for (k=0;k<i;k++)
		{
			double n=k+2;
			R[i][k+1]=1.0/(pow(4,n-1)-1)*(pow(4,n-1)*R[i][k]-R[i-1][k]);
			if (i>0)
			{
				if(fabs(R[i][k+1]-R[i][k]<err))
						return R[i][k+1];
			}
		}
	}
	return R[i][k+1];
}
int main()
{
   int a,b;
   int n,nmax;
   printf("entrez la valeur de a\n");
   scanf("%d",&a);
   printf("entrez la valeur de b\n");
   scanf("%d",&b);
   printf("entrez la valeur de n\n");
   scanf("%d",&n);
   printf("entrez nmax\n");
   scanf("%d",&nmax);
   printf("%lf\n",rectangledr(f,a,b,n));
   printf("%lf\n",rectanglegch(f,a,b,n));
   printf("%lf\n",trap(f,a,b,n));
   printf("%lf\n",simpson(f,a,b,n));
   double err=pow(10,-9);
   printf("nombre necessaire est:");
   printf("%lf\n",nombernecessaire(f,a,b,simpson,err));
   printf("%lf\n",romberg(f,a,b,err,nmax));
   return 0;
}
