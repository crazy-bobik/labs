/*
Операції з матрицями
*/

#include <iostream.h>

//-------------------------------------------------------------------------------------------------------------
//Додавання матриць


void sum(double *a, double *b, double *c, int size_i, int size_j)
{
	int i,j;
	for(i=0;i<=size_i;i++)
	{
		for(j=0;j<=size_j;j++)
		{
			c[i][j] = a[i][j] + b[i][j]; //хулє?!!
		}
	}
}


int main(void)
{
	double a[1][1], b[1][1], c[1][1];
	int i,j;
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=1;j++)
		{
			cin>>a[i][j];
			cin>>b[i][j];
		}
	}
	sum(&a, &b, &c, 1, 1);
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=1;j++)
		{
			cout<<c[i][j]<<"  ";
		}
		cout<<endl;
	}
	return(0);
}
