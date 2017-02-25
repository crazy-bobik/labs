/*
Написано в Kate
Скомпільовано в g++
Явний метод Ейлера розв'язку дифиринціального рівняння виду
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
//функція обрахунку y(n+1), h - ширина кроку

double yn( double x0, double y0, double h, double(*f)(double, double) )
{
	return(y0 + h*f(x0, y0));
}

//--------------------------------------------------------------------------------------------------------
//функція обрахунку y(n+1) з уточненням, h - ширина кроку

double ynt( double x0, double y0, double h, double(*f)(double, double) )
{
	double y;
	y = y0 + h*f(x0, y0);
	return(y0 + h*0.5*(f(x0, y0) + f((x0 + h), y)));
}

int main(void)
{
	int i;
	double s, h; //s - кількість кроків, h - ширина кроку
	double x, y;	

	ifstream input("input.txt");
	ofstream output("output.txt");
	
	input>>x; input>>y;
	input>>s; input>>h;	
	output<<"x"<<"    "<<"y"<<"\n";
	
	for(i=1;i<=s;i++)
	{
		y = ynt(x, y, h, &u);
		x = x + h;
		output<<x<<" "<<y<<"\n";
	}		
		
	return(0);
}
