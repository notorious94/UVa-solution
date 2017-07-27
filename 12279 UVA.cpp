#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 600
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int eb,t,v,k=0;
    while(1)
    {
        sif(t);
        eb=0;
        k++;
        if(t==0)
            break;
        for(int i=1;i<=t;i++)
        {
            sif(v);
            if(v==0)
                eb--;
            else
                eb++;
        }
        pf("Case %d: %d\n",k,eb);
    }
    return 0;
}
