#include <iostream.h>

int sum(int a, int b)
{
	return(a + b);
}

double sum(double a, double b)
{
	return(a + b);
}	


int main(void)
{
	int a=2, b=4;
	
	cout<<sum(2, 3)<<"\n";
	cout<<sum(a, b)<<"\n";
	return(0);
}
