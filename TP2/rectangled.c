#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float x)
{
	return x*x;
}
int main()
{
	float a = 0, b = 4;
	int n = 20;
	float h;
	h = (b - a) / n;
	int i;
	float somme, I;
	somme = 0;
	for(i = 0; i<n - 1;i++)
	{
		somme=somme+(h*f(a+(i*h)));
	}
I = somme;
printf("%lf\n" , I);
}
