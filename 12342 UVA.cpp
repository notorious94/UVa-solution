#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int test, caseno = 0;
    scanf("%d", &test);
    while(test--)
    {
        int amount;
        double tax=0;
        scanf("%d", &amount);
        int a = amount - 180000;
        int b = a - 300000;
        int c = b - 400000;
        int d = c - 300000;
        if(a>0)
        {
            if(b>0)
                a = 300000;
            double ta = a * 0.1;
            if(ta<2000)
                ta = 2000;
            tax = tax + ta;
        }
        if(b>0)
        {
            if(c>0)  b = 400000;
            double ta = b * 0.15;
            tax = tax + ta;
        }
        if(c>0)
        {
            if(d>0) c = 300000;
            double ta = c * 0.2;
            tax = tax + ta;
        }
        if(d>0)
        {
            double ta = d*0.25;
            tax = tax + ta;
        }
        printf("Case %d: %0.0lf\n",++caseno, ceil(tax));
    }
    return 0;
}

