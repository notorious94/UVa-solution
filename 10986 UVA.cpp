#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 20005
#define INF 999999
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

class node
{
public:
    int n,w;
    node(int a,int b){n=a; w=b;}
    bool operator <(const node& p) const { return w>p.w; }
};

int dijkstra(vector<int>graph[], vector<int>cost[], int s, int t)
{
    int dis[MAX];
    for(int i=0;i<MAX;i++)
        dis[i] = INF;
    priority_queue<node>pq;
    pq.push(node(s,0));
    dis[s]=0;

    while(pq.size())
    {
        node top = pq.top();
        if(top.n==t)  return dis[t];
        pq.pop();

        int u = top.n;

        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(dis[u]+cost[u][i]<dis[v])
            {
                dis[v]=dis[u]+cost[u][i];
                pq.push(node(v,dis[v]));
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test,n,m,s,t;
    int u,v,w;

    scanf("%d",&test);
    for(int kase =1;kase<=test;kase++)
    {
        scanf("%d%d%d%d",&n,&m,&s,&t);
        vector<int>graph[MAX],cost[MAX];
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        int ans = dijkstra(graph,cost,s,t);

        if(ans==-1)
            printf("Case #%d: unreachable\n",kase);
        else
            printf("Case #%d: %d\n",kase,ans);
    }

    return 0;
}
