#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int t,w,n;
int dir[31][1005],dp[31][1005];
int d[31],gold[31];
vector<int>items;

int Knapsack(int i=0,int air=0)
{
    if(i==n)    return 0;
    if(dp[i][air]!=-1)  return dp[i][air];
    int p1 = 0,p2 = 0;
    if(air+3*w*d[i]<=t)
        p1 = gold[i] + Knapsack(i+1,air+3*w*d[i]);
    p2 = Knapsack(i+1,air);
    if(p1>p2)   dir[i][air] = 1;
    else        dir[i][air] = 2;
    return dp[i][air] = max(p1,p2);
}

int take(int i=0,int a=0)
{
    if(dir[i][a]==-1)   return 0;
    if(dir[i][a]==1)
    {
        items.push_back(i);
        return 1 + take(i+1,a+3*w*d[i]);
    }
    else
        return take(i+1,a);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k=0;

    while(scanf("%d%d",&t,&w)==2)
    {
        if(++k>1)   puts("");
        scanf("%d",&n);

        mem(dir,-1);
        mem(dp,-1);

        for(int i=0;i<n;i++)
            scanf("%d%d",&d[i],&gold[i]);

        items.clear();

        pif(Knapsack());
        pif(take());

        for(int i=0;i<items.size();i++)
            printf("%d %d\n",d[items[i]],gold[items[i]]);

    }
    return 0;
}
