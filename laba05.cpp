/*
Написано в Kate
Скомпільовано в g++
Метод Рунге-Кунта розв'язку дифиринціального рівняння виду
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
//k1

inline double k1( double x, double y, double h, double(*f)(double, double) )
{
	return(h*f(x, y));
}

//--------------------------------------------------------------------------------------------------------
//k2

inline double k2( double x, double y, double h, double(*f)(double, double), double q1 )
{
	return(h*f((x + (h*0.5)), y + (q1*0.5)));
}

//--------------------------------------------------------------------------------------------------------
//k2

inline double k3( double x, double y, double h, double(*f)(double, double), double q2 )
{
	return(h*f((x + (h*0.5)), y + (q2*0.5)));
}

//--------------------------------------------------------------------------------------------------------
//k4

inline double k4( double x, double y, double h, double(*f)(double, double), double q3 )
{
	return(h*f((x + h), y + q3));
}

//--------------------------------------------------------------------------------------------------------
//Yn

inline double Yn( double y, double q1, double q2, double q3, double q4 )
{
	return(y + (0.1666)*(q1 + 2*(q2 + q3) + q4));// (1/6) не працює чогось ????
}

int main(void)
{
	int i, s;
	double e; //s - кількість кроків, e - ширина кроку
	double x, y;
	double q1, q2, q3 ,q4;

	ifstream input("input.txt");
	ofstream output("runge.txt");
	
	input>>x; input>>y;
	input>>s; input>>e;	
	output<<"x"<<"    "<<"y"<<"\n";
	
	for(i=1;i<=s;i++)
	{
		
		q1 = k1(x, y, e, &u);		cout<<q1<<"\n";
		q2 = k2(x, y, e, &u, q1);	cout<<q2<<"\n";
		q3 = k3(x, y, e, &u, q2);	cout<<q3<<"\n";
		q4 = k4(x, y, e, &u, q3);	cout<<q4<<"\n";
		y = Yn(y, q1, q2, q3, q4);	cout<<y<<"\n";
		x = x + e;
		output<<x<<" "<<y<<"\n";
	}		
	return(0);
}
