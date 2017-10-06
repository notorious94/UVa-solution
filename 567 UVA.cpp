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

typedef long long ll;
typedef unsigned long long ull;

int BFS(vector<int>graph[],int s, int e)
{
    bool visit[21];
    memset(visit, false, sizeof(visit));
    int level[21];

    queue<int>q;
    q.push(s);
    level[s]=0;
    visit[s]=true;

    while(q.size()!=0)
    {
        int u = q.front();
        q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(visit[v]==false)
            {
                visit[v]=true;
                level[v]=level[u]+1;
                q.push(v);
            }
        }
        if(visit[e]==true)
            break;
    }
    return level[e];
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int c,a,n,node;
    int kase=0;

    while(scanf("%d",&c)!=EOF)
    {
        vector<int>graph[21];
        kase++;
        n=1;
        node = 18;
        while(c--) /// Input for First Node
        {
            scanf("%d", &a);
            graph[n].push_back(a);
            graph[a].push_back(n);
        }
        while(node--) /// Remaining Nodes
        {
            scanf("%d",&c);
            n++;
            while(c--)
            {
                scanf("%d", &a);
                graph[n].push_back(a);
                graph[a].push_back(n);
            }
        }
        int q,s,e;
        scanf("%d", &q);
        printf("Test Set #%d\n",kase);
        while(q--)
        {
            scanf("%d%d",&s,&e);
            int ans = BFS(graph, s,e);
            printf("%2d to %2d: %d\n",s,e,ans);
        }
        printf("\n");
    }
    return 0;
}
