#include<bits/stdc++.h>
using namespace std;

int main()
{

    double r,x,y,d,min,max;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf%lf%lf",&x,&y,&r);
        d=pow(x*x+y*y,0.5);
        min=fabs(r-d), max=fabs(r+d);
        if(min>max)
            swap(min,max);
        printf("%0.2lf %0.2lf\n",min,max);
    }
    return 0;
}
