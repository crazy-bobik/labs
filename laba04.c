/*
Написано в Kate
Скомпільовано в g++
Неявний метод Ейлера розв'язку дифиринціального рівняння виду
U'=f(x;y) з початковою умовою U(xn)=Un
*/

#include <iostream.h>
#include <cmath>
#include <fstream.h>

//--------------------------------------------------------------------------------------------------------
//рівняння виду u'=f(x;y)

double u(double x, double y)
{
	return(-2*y);
	//return(x-y);
}

//--------------------------------------------------------------------------------------------------------
//функція обчислення y(n+1) методом простої ітерації

double iter(double x, double y0, double(*f)(double, double), double h)
{
	double y = y0;
	int i;

	for(i=1;i<=10;i++)
	{
		y=y0+h*f(x, y);
	}
	return(y);
}


int main(void)
{

	int i, s;
	double e; //s - кількість кроків, e - ширина кроку
	double x, y;	

	ifstream input("input.txt");
	ofstream output("output2.txt");
	
	input>>x; input>>y;
	input>>s; input>>e;	
	output<<"x"<<"    "<<"y"<<"\n";
	
	for(i=1;i<=s;i++)
	{
		x = x + e;
		y = iter(x, y, &u, e);
		//x = x + e;
		output<<x<<" "<<y<<"\n";
	}		
	return(0);
}
