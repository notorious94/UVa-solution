#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 9999999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int graph[11][11],path[11][11];

void setINF(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            graph[i][j] = (i==j) ? 0 : INF;
            path[i][j] = i;
        }
    }
}

void findPath(int s, int d)
{
    if(s==d)
    {
        printf("Path = %d",s);
        return;
    }
    findPath(s,path[s][d]);
    printf(" %d",d);
}

int floyedWarshall(int n,int s,int d)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(graph[i][k]+graph[k][j]<graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    path[i][j] = path[k][j];
                }
            }
    return graph[s][d];
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,c,r,cost,kase=0;
    int s,d;

    while(scanf("%d",&n))
    {
        if(!n)  break;

        setINF(n);

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&r);
            while(r--)
            {
                scanf("%d%d",&c,&cost);
                if(cost<graph[i][c])
                    graph[i][c] = cost;
            }
        }
        scanf("%d%d",&s,&d);
        int time = floyedWarshall(n,s,d);

        printf("Case %d: ",++kase);
        findPath(s,d);
        printf("; %d second delay\n",time);
    }

    return 0;
}
