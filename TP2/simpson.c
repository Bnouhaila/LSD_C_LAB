#include<stdio.h>
#include<math.h>
double f(double x)
{
	return 2*x*x;
}
double simpson(int n, double a, double b)
{
	double x, h, I0, I1, I2, I;
	int i;
	h=(b-a)/n;
	I0= f(a) + f(b);
	I1= 0;
	I2=0;
	for(i=0; i<n-1; i++)
	{
		x= a + i*h;
		if((i%2) == 0)
			I2= I2 +f(x);
		else
			I1= I1 + f(x);
	}
	I = (I0 + 2*I2 + 4*I1) *h /3;
	return(I);
}
int main()
{
	int i,n;
	double a,b,s;
	a=1;
	b=4;
	n=20;
	simpson(n,a,b);
	s=simpson(n,a,b);
	printf("%lf\n", s);
	return 0;

}


