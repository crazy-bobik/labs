/*
Написано в Kate
Скомпільовано через g++
Розв'язок системи диренціальних рівнянь методом
Рунге-Кутта-Мерсона з автоматичним вибором кроку
*/


/*________________________________________________________________________________________________________
\ Для себе:
\ sys: приймає поточний x, вектор y і його довжину n; повертає вектор значень довжини n;
\ k1:  приймає поточний x, вектор y і його довжину n, вказівник на систему;
\ ...
\ k5:...
\ accuracy: приймає вектори k1, k3, k4, k5 та їх довжину n; повертає вектор похибки довжиною n;
\ ypp: приймає вектори y, k1, k4, k5 та їх довжину n; повертає вектор y(n+1);
\ correct: приймає величину похибки e, вектор похибок d, вектор величин кроків h та їх довжинк n;
________________________________________________________________________________________________________*/

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
void k1( double x, double *y, double *q1, double *h, int size, double(*f)(double, double*, double*, int) )
{
	int i;
	double a[size];
	sys(x, y, a, size);
	for(i=0;i<=size;i++)
	{
		q[i] = (t)*h[i]*a[i]);
	}
}

//--------------------------------------------------------------------------------------------------------
//k2
void k2( double x, double *y, double *q2, double *h, int size, double(*f)(double, double*, double*, int), double *q1 )
{
	int i;
	double a[size];
	for(i=0;i<=size;i++)
	{
    		q2[i] = (t)*h[i]*f((x + t*h[i]),(y[i] + q1[i]));
	}
}

//--------------------------------------------------------------------------------------------------------
//k3
void k3( double x, double *y, double *q3, double *h, int size, double(*f)(double, double*, double*, int), double *q1, double *q2 )
{
	int i;
	for(i=0;i<=size;i++)
	{
		q3[i] = (t)*h[i]*f((x + t*h[i]),(y[i] + 0.5*q1[i] + 0.5*q2[i]));
	}
}

//--------------------------------------------------------------------------------------------------------
//k4
void k4( double x, double *y, double *q4, double *h, int size, double(*f)(double, double*, double*, int), double *q1, double *q3 )
{	
	int i;
	for(i=0;i<=size;i++)
	{
		q4[i] = (t)*h*f((x + 0.5*h[i]),(y[i] + 0.375*q1[i] + 2.125*q3[i]));
	}
}

//--------------------------------------------------------------------------------------------------------
//k5
void k5( double x, double *y, double *q5, double *h, int size, double(*f)(double, double*, double*, int), double *q1, double *q3, double *q4 )
{
	int i;
	for(i=0;i<=size;i++)
	{
		q5[i] = (t)*h[i]*f((x + h[i]),(y[i] + 1.5*q1[i] - 4.5*q3[i] + 6*q4[i]));
	}
}

//--------------------------------------------------------------------------------------------------------
//похибка на кроці
void accuracy( double *d, double *q1, double *q3, double *q4, double *q5, int size )
{	
	int i;
	for(i=0;i<=size;i++)
	{
		d[i] = (q1[i] - 4.5*q3[i] + 4*q4[i] - 0.5*q5[i]);
	}
}

//--------------------------------------------------------------------------------------------------------
//Y(n+1)
void ypp( double *yn, double *y, double *q1, double *q4, double *q5 )
{
	int i;
	for(i=0;i<=size;i++)
	{
		yn[i] = (y[i] + 0.5*(q1[i] + 4*q4[i] + q5[i]));
	}
}

//--------------------------------------------------------------------------------------------------------
//функція корекції кроку
void correct(double e, double *d, double *h, int size)
{
	for(i=0;i<=size;i++)
	{ 
	if( fabs(d[i])>e )
    	{
        	h[i] = 0.5*h[i];
    	}
    	else
    	{
        	if( fabs(d[i])<(0.03125*e) )
            	{
                   	h[i] = 2*h[i];
            	}
        	else
        	{
                	if( fabs(d[i])<=e) && ( fabs(d[i])>=(0.03125*e)) )
                	{
				h[i] = h[i];
                	}
        	}	
    	};

	}
}

/*//________________________________________________________________________________________________________
int main(void)
{
    	double xk, h[2], e; //xk - кінцева точка, h - ширина кроку, e - похибка
	double x[2], y[2];
    	double q1[2], q2[2], q3[2], q4[2], q5[2];	
    	double p, ch[2]; //p - похибка на кроці, m - коригований крок

	ifstream input("input.txt");
	ofstream output("output.txt");
	
	input>>x; input>>y; input>>xk;	
	output<<"x"<<"    "<<"y"<<endl;
	output<<x<<"    "<<y<<endl;
	
    	cout<<"Null step:";  cin>>h; //і чому вінда унікод не юзає!??
    	cout<<"Accuracy:";  cin>>e;
	
	while(x<=xk)
	{
           q1 = k1(&x, &y, &h, &u);
           q2 = k2(x, y, h, &u, q1);
           q3 = k3(x, y, h, &u, q1, q2);
           q4 = k4(x, y, h, &u, q1, q3);
           q5 = k5(x, y, h, &u, q1, q3, q4);
           p = accuracy(q1, q3, q4, q5);
           ch = correct(e, p, h);
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

*/