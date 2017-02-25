//обрахунок експоненти
#include <iostream.h>
#include <cmath>

double fak(double a)
{
	double i, b=1.0;
	for(i=2.0;i<=a;i++)
	{
		b = b*i;
	}
	return(b);
}

double exp(double x, double b)
{
	double e = (1.0/b);
	double tmp = 1.0 + x;
	double i;
	for(i=2.0;tmp>=e;i++)
	{
		tmp = tmp + (pow(x, i)/fak(i));
	}
	return(tmp);
}

int main(void)
{
	double x, b;
	cin>>x;
	cin>>b;
	cout<<exp(x, b);
	return(0);
}
