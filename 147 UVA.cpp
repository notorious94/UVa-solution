#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int coin[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
ll dp[30001];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mem(dp,0);
    dp[0] = 1;
    for(int i=0;i<11;i++)
        for(int j = coin[i],k=0;j<=30000;j++,k++)
            dp[j]+=dp[k];

    float m;
    while(scanf("%f",&m))
    {
        if(m==0.00)
            break;
        /// Rounding Error Fix
        unsigned n = (unsigned)((m + 0.001) * 100);

        pf("%6.2lf%17lld\n",m,dp[n]);
    }

    return 0;
}
