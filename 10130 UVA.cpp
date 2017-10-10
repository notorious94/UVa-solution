#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int n,cap;
int w[1001];
int p[1001];
int dp[1001][1001];

int knapsack(int i, int wt)
{
    if(i==n+1)  return 0;

    if(dp[i][wt]!=-1) return dp[i][wt];

    int cost1 = 0, cost2 = 0;

    if(wt + w[i]<=cap)
        cost1 = p[i] + knapsack(i+1,wt+w[i]);

    cost2 = knapsack(i+1,wt);

    dp[i][wt] = max(cost1, cost2);

    return dp[i][wt];
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(int i=1;i<=n;i++)
            scanf("%d%d",&p[i],&w[i]);

        int g;
        int sum=0;

        scanf("%d",&g);

        while(g--)
        {
            scanf("%d",&cap);
            memset(dp,-1,sizeof(dp));
            sum+=knapsack(1,0);
        }

        cout<<sum<<endl;
    }

    return 0;
}
