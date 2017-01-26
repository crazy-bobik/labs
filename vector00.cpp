/*
÷€цьканн€ з векторами
*/

#include <iostream.h>

const int n=3;

int* summ(int* a, int* b)
{
    int* c = new int[n];
    int i;
    for(i=1;i<=n;i++)
    {
        c[i] = a[i] + b[i];
    }
    return(c);
}

int main(void)
{
    int a[n], b[n], c[n];
    int i;
    for(i=1;i<=n;i++)
    {
        cout<<i<<endl;
        cin>>a[i];
        cin>>b[i];
    }
    c = summ(a, b);
    for(i=1;i<=n;i++)
    {
        cout<<c[i]<<endl;
    }
    system("PAUSE");
    return(0);
}
