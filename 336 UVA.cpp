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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nc,a,b,s,ttl,kase=0;

    while(sf("%d", &nc))
    {
        if(!nc)
            break;

        map<int, vector<int> > graph;
        map<int, vector<int> > :: iterator it_g;

        for(int i=0;i<nc;i++)
        {
            sf("%d%d",&a,&b);

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        while(sf("%d%d",&s, &ttl))
        {
            if(s==0&&ttl==0)
                break;
            kase++;

            map<int, bool>visit;
            map<int, int>level;
            map<int, int> :: iterator it;

            for(it_g = graph.begin() ; it_g != graph.end() ; it_g ++)
            {
                visit[it_g->first] = false;
                level[it_g->first] = -1;
            }

            queue<int>Q;

            Q.push(s);
            visit[s]=true;
            level[s]=0;

            while(Q.size()!=0)
            {
                int u = Q.front();
                Q.pop();
                for(int i=0;i<graph[u].size();i++)
                {
                    int v = graph[u][i];
                    if(visit[v]==false)
                    {
                        visit[v]=true;
                        level[v] = level[u] + 1;
                        Q.push(v);
                    }
                }
            }

            int count = 0;

            for(it = level.begin();it!=level.end();it++){
                if(it->second<=ttl&&it->second!=-1)
                    count++;
            }

            int ans=graph.size()-count;

            pf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",kase,ans,s,ttl);
        }
    }

    return 0;
}
