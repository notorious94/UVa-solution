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
#define mem(name, value) memset(name, value, sizeof(name))

int g[301][301], p[301][301];
char s[MAX];

void reset(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            p[i][j] = i;
            g[i][j] = (i==j) ? 0 : INF;
        }
}

void floyd_warshall(int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(g[i][k]!=INF&&g[k][j]!=INF)
                {
                    if(g[i][j]>g[i][k]+g[k][j])
                    {
                        g[i][j] = g[i][k] + g[k][j];
                        p[i][j] = p[k][j];
                    }
                }
}

void pathFind(int s, int d)
{
    if(s==d)
    {
        pf("%d",s);
        return;
    }
    pathFind(s,p[s][d]);
    pf(" %d",d);
}

void input(int n)
{
    for(int i=1;i<=n;i++)
    {
        sf("%s",s);
        char *pch = strtok(s,"-,");
        int u = atoi(pch),v;
        while(pch!=NULL)
        {
            v = atoi(pch);
            g[u][v] = 1;
            pch = strtok(NULL,"-,");
        }
    }
    floyd_warshall(n);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q,src,dis;

    while(scanf("%d",&n)==1)
    {
        pf("-----\n");
        reset(n);
        input(n);
        sif(q);
        while(q--)
        {
            sf("%d%d",&src,&dis);
            if(g[src][dis]==INF)
                pf("connection impossible\n");
            else
            {
                pathFind(src,dis);
                puts("");
            }
        }
    }
    return 0;
}
