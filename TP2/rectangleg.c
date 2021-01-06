#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double(x))
{
	return x*x;
}
int main()
{
	double a=1;
	double b=4;
	int n=20;
	double h;
	h=(b-a)/n;
	int i;
	double s, I;
	s=0;
	for(i=0;i<n-1;i++)
	{
		s+=h*f(a+(i*h)+h/2);
	}
I=s;
printf("%lf\n", I);
}
