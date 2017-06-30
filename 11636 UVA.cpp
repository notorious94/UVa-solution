#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,count;
    for(int i=1;;i++)
    {
        scanf("%d", &n);
        if(n<0)
            break;
        count=0;
        a=1;
        while(a<n)
        {
            a*=2;
            count++;
        }
        printf("Case %d: %d\n",i,count);
    }
    return 0;
}
