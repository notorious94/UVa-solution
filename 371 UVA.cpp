#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll c;

ll af(ll n)
{
    ++c;
    if(n==1&&c>1)
        return c-1;
    else if(n%2==0)
        af(n/2);
    else
        af(3*n+1);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll x,y,max,n,call,temp;
    while(1)
    {
        scanf("%llu%llu",&x,&y);
        if(x==0&&y==0)
            break;
        if(x>y)
        {
            temp=x;
            x=y;
            y=temp;
        }
        printf("Between %llu and %llu, ",x,y);
        max=0;
        for(;x<=y;x++)
        {
            call=af(x);
            if(max<call)
            {
                max=call;
                n=x;
            }
            c=0;
        }
        printf("%llu generates the longest sequence of %llu values.\n",n,max);
    }
    return 0;
}
