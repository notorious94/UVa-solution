#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};

bool visit[26];
vector<int>adj[26];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string zone,edge;
    int n,m;
    while(cin>>n)
    {
        memset(visit,false,sizeof(visit));

        for(int i=0;i<26;i++)
            adj[i].clear();

        cin>>m>>zone;

        set<int>nodes;

        for(int i=0;i<3;i++)
        {
            nodes.insert(zone[i]-'A');
            visit[zone[i]-'A'] = true;
        }

        while(m--)
        {
            cin>>edge;

            int u = edge[0]-'A';
            int v = edge[1]-'A';

            nodes.insert(u);
            nodes.insert(v);

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        if(nodes.size()<n)
        {
            printf("THIS BRAIN NEVER WAKES UP\n");
            continue;
        }

        int year = 0,total = 3;

        while(total<n)
        {
            vector<int>temp;
            for(auto it = nodes.begin();it!=nodes.end();it++)
            {
                int u = *it;
                int in_degree = 0;
                if(visit[u]==false)
                {
                    for(int i=0;i<adj[u].size();i++)
                    {
                        int v = adj[u][i];
                        if(visit[v]==true)
                            in_degree++;
                    }
                    if(in_degree>=3)    temp.push_back(u);
                }
            }
            if(temp.size()==0)  break;
            total+=temp.size();
            for(int i=0;i<temp.size();i++)
                visit[temp[i]] = true;
            year++;
        }
        if(total==n)
            printf("WAKE UP IN, %d, YEARS\n",year);
        else
            printf("THIS BRAIN NEVER WAKES UP\n");
    }
    return 0;
}

