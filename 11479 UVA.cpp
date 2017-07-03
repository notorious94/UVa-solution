#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;

int main()
{
    llu t,a[3],i=0;
    scanf("%llu",&t);
    while(t--)
    {
        i++;
        scanf("%llu%llu%llu", &a[0],&a[1],&a[2]);
        sort(a, a+3);
        printf("Case %llu: ", i);
        if(a[0]+a[1]<=a[2])
            printf("Invalid\n");
        else
        {
            if(a[0]==a[1]&&a[1]==a[2])
                printf("Equilateral\n");
            else if(a[0]==a[1]||a[1]==a[2])
                printf("Isosceles\n");
            else
                printf("Scalene\n");
        }
    }
    return 0;
}
