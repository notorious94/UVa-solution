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

int coin[] = {1,5,10,25,50};
ll dp[5][30001];

ll coinChange(int i, int amount)
{
    if(i>=5)
    {
        if(!amount) return 1;
        else        return 0;
    }
    if(dp[i][amount]!=-1)   return dp[i][amount];
    ll r1 = 0, r2;
    if(amount-coin[i]>=0)
        r1 = coinChange(i,amount-coin[i]);
    r2 = coinChange(i+1, amount);
    return dp[i][amount] = r1 + r2;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mem(dp,-1);
    coinChange(0,30000);
    int make;

    while(scanf("%d",&make)!=EOF)
    {
        ll ans = coinChange(0,make);

        if(ans==1)
            pf("There is only %lld way to produce %d cents change.\n",ans,make);
        else
            pf("There are %lld ways to produce %d cents change.\n",ans,make);
    }
    return 0;
}
