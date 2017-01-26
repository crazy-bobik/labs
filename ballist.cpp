/*
Написано в Kate
Скомпільовано через g++
Задача балістики:
---------------------------------------------------
V(x;k+1) = V(x;k) - t*b*Vk*V(x;k)
V(h;k+1) = V(h;k) - t*b*Vk*V(h;k) - t*g
		Vk = sqrt( V(x;k)^2 + V(h;k)^2 )
---------------------------------------------------
X(k+1) = X(k) + t*V(x;k)
H(k+1) = H(k) + t*V(h;k)
---------------------------------------------------
Початкові умови
V(x;0) = V(0)*cos(a)
V(h;0) = V(0)*sin(a)
---------------------------------------------------
Вхід:
V(0) - модуль початкової швидкості [м/с]
a - кут до горизонту [рад]
m - маса [кг]
k - коефіцієнт опору повітря 
t - крок
*/

#include <iostream.h>
#include <fstream.h>
#include <cmath>

//--------------------------------------------------------------------------------------------------------
//функція обрахунку V(x;k+1)
//Vk <=> V(k); Vxk <=> V(x;k+1); t - величина кроку; b = k/m - коефіцієнт опору повітря

double Vx( double Vk, double Vxk, double t, double b )
{
	return(Vxk - t*b*Vk*Vxk);
}

//--------------------------------------------------------------------------------------------------------
//V(h;k+1)
//Vk <=> V(k); Vhk <=> V(h;k+1); t - величина кроку; b = k/m - коефіцієнт опору повітря

double Vh( double Vk, double Vhk, double t, double b )
{
	return(Vhk - t*(b*Vk*Vhk + 9.82));
}

//--------------------------------------------------------------------------------------------------------
//функція обрахунку X
// десь тут чорна магія

double Xk( double X, double t, double Vk, double Vxk, double b, double(*f)(double, double, double, double) )// this is magic
{
	return(X + t*f(Vk, Vxk, t, b));
}

//--------------------------------------------------------------------------------------------------------
//функція обрахунку H

double Hk( double H, double t, double Vk, double Vhk, double b, double(*f)(double, double, double, double) )// this is magic too
{
	return(H + t*f(Vk, Vhk, t, b));
}

int main(void)
{
	int i;                        //лічільник
	double V0, a, m, k, t;        //вхідні величини
	double b, Vk, X, H, Vxk, Vhk; //величини, що обчислюються

	ofstream output("ballist.txt");

	cout<<"Початкова швидкість V0:"; cin>>V0;
	cout<<"Кут до горизонту a (в радіанах):"; cin>>a;
	cout<<"Маса тіла m:"; cin>>m;
	cout<<"Коефіцієнт опору k:"; cin>>k;
	cout<<"Величина кроку t:"; cin>>t;

	b = k/m;
	Vxk = V0*cos(a); X = 0;
	Vhk = V0*sin(a); H = 0;
	
	for(i=0;H>=0;i++)
	{
		Vk=sqrt(pow(Vxk, 2) + pow(Vhk, 2));
		X = Xk( X, t, Vk, Vxk, b, &Vx );	
		H = Hk( H, t, Vk, Vhk, b, &Vh );	
		output<<X<<"        "<<H<<"\n";
		Vxk = Vx(Vk, Vxk, t, b);
		Vhk = Vh(Vk, Vhk, t, b);
	}
	return(0);
}
