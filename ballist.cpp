/*
�������� � Kate
������������ ����� g++
������ ��������:
---------------------------------------------------
V(x;k+1) = V(x;k) - t*b*Vk*V(x;k)
V(h;k+1) = V(h;k) - t*b*Vk*V(h;k) - t*g
		Vk = sqrt( V(x;k)^2 + V(h;k)^2 )
---------------------------------------------------
X(k+1) = X(k) + t*V(x;k)
H(k+1) = H(k) + t*V(h;k)
---------------------------------------------------
�������� �����
V(x;0) = V(0)*cos(a)
V(h;0) = V(0)*sin(a)
---------------------------------------------------
����:
V(0) - ������ ��������� �������� [�/�]
a - ��� �� ��������� [���]
m - ���� [��]
k - ���������� ����� ������ 
t - ����
*/

#include <iostream.h>
#include <fstream.h>
#include <cmath>

//--------------------------------------------------------------------------------------------------------
//������� ��������� V(x;k+1)
//Vk <=> V(k); Vxk <=> V(x;k+1); t - �������� �����; b = k/m - ���������� ����� ������

double Vx( double Vk, double Vxk, double t, double b )
{
	return(Vxk - t*b*Vk*Vxk);
}

//--------------------------------------------------------------------------------------------------------
//V(h;k+1)
//Vk <=> V(k); Vhk <=> V(h;k+1); t - �������� �����; b = k/m - ���������� ����� ������

double Vh( double Vk, double Vhk, double t, double b )
{
	return(Vhk - t*(b*Vk*Vhk + 9.82));
}

//--------------------------------------------------------------------------------------------------------
//������� ��������� X
// ���� ��� ����� ����

double Xk( double X, double t, double Vk, double Vxk, double b, double(*f)(double, double, double, double) )// this is magic
{
	return(X + t*f(Vk, Vxk, t, b));
}

//--------------------------------------------------------------------------------------------------------
//������� ��������� H

double Hk( double H, double t, double Vk, double Vhk, double b, double(*f)(double, double, double, double) )// this is magic too
{
	return(H + t*f(Vk, Vhk, t, b));
}

int main(void)
{
	int i;                        //��������
	double V0, a, m, k, t;        //����� ��������
	double b, Vk, X, H, Vxk, Vhk; //��������, �� ������������

	ofstream output("ballist.txt");

	cout<<"��������� �������� V0:"; cin>>V0;
	cout<<"��� �� ��������� a (� �������):"; cin>>a;
	cout<<"���� ��� m:"; cin>>m;
	cout<<"���������� ����� k:"; cin>>k;
	cout<<"�������� ����� t:"; cin>>t;

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
