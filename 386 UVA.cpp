#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i;
    for(i=6;i<=200;i++)
        for(int a=2;a<=i;a++)
            for(int b=a+1;b<=i;b++)
                for(int c=b+1;c<=i;c++)
                    if(i*i*i==a*a*a+b*b*b+c*c*c)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,a,b,c);

    return 0;
}
