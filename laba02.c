/*
Написано в Kate
Скомпільовано в g++
Квадратурна формула Гауса
*/
#include <iostream.h>
#include <cmath>

//--------------------------------------------------------------------------------------------------------
//інтегровна функція

double f(double x)
{
	return(pow(x,2));
}

//--------------------------------------------------------------------------------------------------------
//квадратура Гауса для двох вузлів

double gs(double a, double b, double(*y_)(double), int s)
{
	double x, l;
	double Sum;
	int i;

	Sum = 0;
	x = (b - a)/s;
	l = a - x;

	for(i=1;i<=s;i++)
	{
		l = l + x;
		Sum = Sum + (x/2)*(y((2*l+x)/2 - x/2*sqrt(3))+y((2*l+x)/2 + x/2*sqrt(3)));
	}

	return(Sum);
}

int main(void)
{
	double a,b;
	int s;

	cout<<"a:";cin>>a;
	cout<<"b:";cin>>b;
	cout<<"s:";cin>>s;
	cout<<"Гауса:"<<gs(a, b, s)<<"\n";
	
	return(0);
}
