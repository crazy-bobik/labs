#include <iostream.h>
#include <cmath>
#include <fstream.h>

/*void f(double x, double *y, double *rhs, int size)
{
	int i;
	for(i=1;i<=size;i++)
	{
		rhs[i] = x*y[i];
	}
}
*/
const double t = 1.0/3.0;

//--------------------------------------------------------------------------------------------------------
//рівняння виду u'=f(x;y)

double sys(double x, double *y, double *u, int size)
{
	u[1] = (-2*y[1]);
	u[2] = (x-y[2]);
}

//--------------------------------------------------------------------------------------------------------
//k1
void k1( double x, double *y, double *q1, double h, int size, double(*f)(double, double*, double*, int) )
{
	int i;
	double a[size];
	sys(x, y, a, size);
	for(i=1;i<=size;i++)
	{
		q1[i] = (t)*h*a[i];
	}
}


int main(void)
{
	int n=2;
	int i;
	double x = 1;
	double h = 0.5;
	double y[n], q[n];
	y[1] = 1; y[2] = 7;
	k1(x, y, q, h, n, &sys);
	for(i=1;i<=n;i++)
	{
		cout<<q[i]<<endl;
	}
	
	return(0);
}
