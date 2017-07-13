
#include<bits/stdc++.h>
using namespace std;

///Template Starts Here
#define pf printf
#define sf scanf
#define MAX 600

typedef long long ll;
typedef unsigned long long ull;

int m;

int bigmod(int b,int p)
{
    if(p==0)
        return 1;
    else if(p&1)
        return ((b%m)*(bigmod(b,p-1)%m))%m;
    else
    {
        int ret=bigmod(b,p/2);
		return ((ret%m)*(ret%m))%m;
    }
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int b,p;

    while(sf("%d%d%d",&b,&p,&m)!=EOF)
    {
        pf("%d\n",bigmod(b,p));
    }
    return 0;
}
