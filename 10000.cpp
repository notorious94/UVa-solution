#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MIN
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int g[101][101],p[101][101];

void reset(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i][j] = (i==j) ? 0 : INF;
}

void floyedWarshall(int n)
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(g[i][k]!=INT_MIN && g[k][j]!=INT_MIN){
                    if(g[i][j]<g[i][k]+g[k][j])
                        g[i][j] = g[i][k] + g[k][j];
                }
}

int find_answer(int s, int n)
{
    int distance = INF;
    int destination;
    for(int i=1;i<=n;i++)
        if(g[s][i]>distance)
        {
            distance = g[s][i];
            destination = i;
        }
    return destination;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,y,source,exit,kase = 0;
    while(scanf("%d",&n))
    {
        if(!n)  break;

        reset(n);
        scanf("%d",&source);

        while(scanf("%d%d",&x,&y))
        {
            if(!x && !y)    break;
            g[x][y] = 1;
        }

        floyedWarshall(n);
        exit = find_answer(source,n);

        pf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++kase,source,g[source][exit],exit);
    }
    return 0;
}
