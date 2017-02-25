/*
Написано в середовищі Dev-Cpp
Скомпільвано через g++
*/

#include <iostream.h>

inline double u(double x, double y)
{
	//return(-2*y);
	return(x-y);
}


double eyler_utoch(double(*f)(double, double), double x1, int n)

{
    double x = 0;
    double y = 0;
    double h = (x1 - x)/n;
    double y1;
    int i = 1;
    double f1;
    do
    {
        f1 = f(x, y);
        x = x + h;
        y1 = y + f1*h;
        y = y + h*(f1 + f(x, y1))*0.5;
        //y1 = y;
        cout<<"y:"<<y<<endl;
        i = i + 1;

    }
    while(i<=n);
    return(0);
}

int main(void)
{
    double x;
    int n;
    cin>>x;
    cin>>n;
    eyler_utoch(&u, x, n);
    system("PAUSE");
    return(0);
}

