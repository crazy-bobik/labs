/*
Написано в середовищі Dev-Cpp
Скомпільвано через g++
Розв'язок диферинціального рівняння методом
Рунге-Кутта-Мерсона з автоматичним вибором кроку
*/

#include <iostream.h>
#include <fstream.h>

const double t = 1.0/3.0;

//--------------------------------------------------------------------------------------------------------
//рівняння виду u'=f(x;y)

inline double u(double x, double y)
{
	return(-2*y);
	//return(x-y);
}

//--------------------------------------------------------------------------------------------------------
//k1
inline double k1( double x, double y, double h, double(*f)(double, double) )
{
    	return((t)*h*f(x, y));
}

//--------------------------------------------------------------------------------------------------------
//k2
inline double k2( double x, double y, double h, double(*f)(double, double), double q1 )
{
    	return((t)*h*f((x + t*h),(y + q1)));
}

//--------------------------------------------------------------------------------------------------------
//k3
inline double k3( double x, double y, double h, double(*f)(double, double), double q1, double q2 )
{
    	return((t)*h*f((x + t*h),(y + 0.5*q1 + 0.5*q2)));
}

//--------------------------------------------------------------------------------------------------------
//k4
inline double k4( double x, double y, double h, double(*f)(double, double), double q1, double q3 )
{
    	return((t)*h*f((x + 0.5*h),(y + 0.375*q1 + 2.125*q3)));
}

//--------------------------------------------------------------------------------------------------------
//k5
inline double k5( double x, double y, double h, double(*f)(double, double), double q1, double q3, double q4 )
{
    	return((t)*h*f((x + h),(y + 1.5*q1 - 4.5*q3 + 6*q4)));
}

//--------------------------------------------------------------------------------------------------------
//похибка на кроці
inline double d( double q1, double q3, double q4, double q5 )
{
    	return(q1 - 4.5*q3 + 4*q4 - 0.5*q5);
}

//--------------------------------------------------------------------------------------------------------
//Y(n+1)
inline double yn( double y, double q1, double q4, double q5 )
{
    	return(y + 0.5*(q1 + 4*q4 + q5));
}

//--------------------------------------------------------------------------------------------------------
//функція корекції кроку
double corect(double e, double d, double h)
{
    	if( fabs(d)>e )
    	{
        	return(0.5*h);
    	}
    	else
    	{
        	if( fabs(d)<(0.03125*e) )
            	{
                   	return(2*h);
            	}
        	else
        	{
                	if( fabs(d)<=e) && ( fabs(d)>=(0.03125*e)) )
                	{
				return(h);
                	}
        	}	
    	};

}

//________________________________________________________________________________________________________
int main(void)
{
    	double xk, h, e; //xk - кінцева точка, h - ширина кроку, e - похибка
	double x, y;
    	double q1, q2, q3, q4, q5;	
    	double p, ch; //p - похибка на кроці, m - коригований крок

	ifstream input("input.txt");
	ofstream output("output.txt");
	
	input>>x; input>>y; input>>xk;	
	output<<"x"<<"    "<<"y"<<endl;
	output<<x<<"    "<<y<<endl;
	
    	cout<<"Null step:";  cin>>h; //і чому вінда унікод не юзає!??
    	cout<<"Accuracy:";  cin>>e;
	
	while(x<=xk)
	{
           q1 = k1(x, y, h, &u);
           q2 = k2(x, y, h, &u, q1);
           q3 = k3(x, y, h, &u, q1, q2);
           q4 = k4(x, y, h, &u, q1, q3);
           q5 = k5(x, y, h, &u, q1, q3, q4);
           p = d(q1, q3, q4, q5);
           ch = corect(e, p, h);
           if(ch == h)
           {
                      y = yn(y, q1, q4, q5);
                      x = x + h;
                      output<<x<<"         "<<y<<"         "<<h<<endl;
           }
           else
           {
                      h = ch;
           };          
    	} 
	return(0);
}

