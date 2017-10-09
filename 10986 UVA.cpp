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

map<int,vector<int> > graph;
map<int,vector<int> > cost;
map<int,vector<int> > :: iterator it;

int Dijkstra(int s, int t)
{
    map<int,int>distance;

    for(it = graph.begin();it != graph.end();it++)
        distance[it->first] = INF;

    distance[t]=INF;
    priority_queue<int>Q;
    Q.push(s);
    distance[s]=0;

    while(Q.size())
    {
        int u = Q.top();
        Q.pop();

        for(int i=0;i< graph[u].size();i++)
        {
            int v = graph[u][i];

            if(distance[u] + cost[u][i] < distance[v])
            {
                distance[v]=distance[u] + cost[u][i];
                Q.push(v);
            }
        }
    }
    return distance[t];
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int T,n,m,s,t;
    int x,y,k;

    scanf("%d",&T);

    for(int c=1;c<=T;c++)
    {
        scanf("%d%d%d%d",&n,&m,&s,&t);

        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&k);

            graph[x].push_back(y);
            graph[y].push_back(x);
            cost[x].push_back(k);
            cost[y].push_back(k);
        }

        int res = Dijkstra(s,t);

        if(res==INF)
            printf("Case #%d: unreachable\n",c);
        else
            printf("Case #%d: %d\n",c,res);

        graph.clear();
        cost.clear();
    }

    return 0;
}
