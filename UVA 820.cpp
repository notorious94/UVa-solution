#include<bits/stdc++.h>
using namespace std;

int capacity[105][105],parent[105];
bool visit[105];
int node,edge;

bool isPath(int s,int t)
{
    memset(visit,false,sizeof(visit));
    memset(parent,-1,sizeof(parent));
    visit[s] = true;
    queue<int>q;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int v=1;v<=node;v++)
        {
            if(!visit[v] && capacity[u][v])
            {
                visit[v]  = true;
                parent[v] = u;
                q.push(v);
                if(v==t)    return true;
            }
        }
    }
    return false;
}

int fordFulkerson(int source,int sink)
{
    int maxFlow = 0;
    while(isPath(source,sink))
    {
        int v = sink,min_res_cap = INT_MAX;
        while(parent[v]!=-1)
        {
            int u = parent[v];
            min_res_cap = min(min_res_cap,capacity[u][v]);
            v = u;
        }
        v = sink;
        while(parent[v]!=-1)
        {
            int u = parent[v];
            capacity[u][v] -= min_res_cap;
            capacity[v][u] += min_res_cap;
            v = u;
        }
        maxFlow += min_res_cap;
    }
    return maxFlow;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    for(int kase = 1;cin>>node;kase++)
    {
        if(!node)   break;
        int source,sink,u,v,c;

        memset(capacity,0,sizeof(capacity));

        cin>>source>>sink>>edge;

        while(edge--)
        {
            cin>>u>>v>>c;
            capacity[u][v] += c;
            capacity[v][u] += c;
        }

        int maxFlow = fordFulkerson(source,sink);
        cout<<"Network "<<kase<<endl;
        cout<<"The bandwidth is "<<maxFlow<<".\n\n";
    }

    return 0;
}
