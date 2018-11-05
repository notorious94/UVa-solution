#include<bits/stdc++.h>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

using namespace std;

bool visit[100001],indeg[100001];
vector<int>adj[100001];
vector<int>topsort,components;

void reset(int n)
{
    topsort.clear();
    for(int i=1;i<=n;i++)
    {
        visit[i] = indeg[i] = false;
        adj[i].clear();
    }
}

void DFS1(int u)
{
    visit[u] = true;
    for(int i=0;i<adj[u].size();i++)
        if(visit[adj[u][i]]==false)
            DFS1(adj[u][i]);
    topsort.push_back(u);
}

void call_1(int n)
{
    for(int i=1;i<=n;i++)
        if(visit[i]==false)
            DFS1(i);
}

void DFS2(int u)
{
    visit[u] = true;
    for(int i=0;i<adj[u].size();i++)
        if(visit[adj[u][i]]==false)
            DFS2(adj[u][i]);
    components.push_back(u);
}

void call_2(int n,int k)
{
    mem(visit,false);
    int scc = 0,c = 0;
    for(int i=n-1;i>=0;i--)
        if(visit[topsort[i]]==false)
        {
            components.clear();
            DFS2(topsort[i]);
            for(int j=0;j<components.size();j++)
                if(indeg[components[j]]==false)
                {
                    scc++;
                    break;
                }
            c++;
        }
    printf("Case %d: %d\n",k,max(scc,c));
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,n,e,u,v;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        scanf("%d%d",&n,&e);
        reset(n);
        while(e--)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            indeg[v] = true;
        }

        call_1(n);
        call_2(n,kase);
    }
    return 0;
}
