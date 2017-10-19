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

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

void BFS(vector<int>*g,int n, int s)
{
    bool visit[n+1];
    memset(visit, false, sizeof(visit));
    queue<int>Q;
    Q.push(s);
    while(Q.size())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v = g[u][i];
            if(visit[v]==false)
            {
                visit[v]=true;
                Q.push(v);
            }
        }
    }

    int count = 0;
    for(int i=1;i<=n;i++)
        if(!visit[i])   count++;

    printf("%d", count);

    for(int i=1;i<=n;i++)
        if(!visit[i])   printf(" %d",i);

    printf("\n");
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(scanf("%d",&n))
    {
        if(!n)  break;

        vector<int>g[n+1];

        int e,c;

        while(scanf("%d",&e))
        {
            if(!e)  break;
            while(scanf("%d",&c))
            {
                if(!c)  break;
                g[e].push_back(c);
            }
        }

        int q,s;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&s);
            BFS(g,n,s);
        }
    }

    return 0;
}
