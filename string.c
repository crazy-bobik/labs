/*
Цяцькаюсь зі стрінгом
*/

#include <iostream.h>
#include <fstream.h>
#include <string.h>

int main(void)
{
	int i;
	string a, b;
	ifstream input("text.txt");
	for(i=0;! input;i++)
	{
		input>>a;
		cout<<a<<"\n";
	}
	return(0);
}