#include<bits/stdc++.h>
using namespace std;

///Template Starts Here
#define pf printf
#define sf scanf
#define MAX 600

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,c=0,n,v,max;
    sf("%d",&t);

    while(t--)
    {
        c++;
        max=0;
        sf("%d",&n);
        for(int i=0;i<n;i++)
        {
            sf("%d",&v);
            if(max<v)
                max=v;
        }
        printf("Case %d: %d\n",c,max);
    }

    return 0;
}
