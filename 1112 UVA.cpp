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

typedef long long ll;
typedef unsigned long long ull;

int grid[101][101],t;

void reset(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            grid[i][j] = (i==j) ? 0 : INF;
}

void floyed_warshall(int n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(grid[i][k]!=INF && grid[k][j]!=INF)
                {
                    if(grid[i][j]>grid[i][k]+grid[k][j])
                    {
                        grid[i][j] = grid[i][k]+grid[k][j];
                    }
                }
            }
        }
    }
}

int process(int n, int e)
{
    int count = 0;
    for(int i=1;i<=n;i++)
        if(grid[i][e]<=t)
            count++;
    return count;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,test;
    int a,b,c,e;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d%d%d%d",&n,&e,&t,&m);

        reset(n);

        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(grid[a][b]>c)
                grid[a][b] = c;
        }

        floyed_warshall(n);

        pif(process(n,e));

        if(test)    pf("\n");

    }

    return 0;
}
