#include<stdio.h>
#include<math.h>
double f(double x);
double trap(double(*f)(double x),double a, double b, int n);
int main()
{
	double a,b;
	int n;
	printf("entrez la borne sup\n");
	scanf("%lf", &a);
	printf("entrez la borne  inf\n");
	scanf("%lf", &b);
	printf("entrez le nombre de subduvision\n");;
	scanf("%d", &n);
	printf("%lf", trap(f,a,b,n));
}
double f(double x)
{
	return 2*x;
}
double trap(double(*f)(double x), double a,double b, int n)
{
	double h, resultat, s=0;
	int i;
	h=fabs(b-a)/n;
	for(i=0;i<n-1;i++)
	{
		s+=f(a+i*h);
	}
	resultat=h*((f(a)+f(b)/2) + s);
	return("le resultat est: %lf\n" , resultat);
}
