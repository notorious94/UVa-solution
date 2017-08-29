#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

bool bipar(vector<int>g[], int s, int n)
{
    int color[n];
    bool visit[n];

    memset(color,-1,sizeof(color));
    memset(visit,false,sizeof(visit));

    color[s]=0;
    visit[s]=true;

    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];

            if(visit[v]==false)
            {
                visit[v]=true;
                if(color[u]==0)
                    color[v] = 1;
                else
                    color[v] = 0;
                q.push(v);
            }

            if(visit[v]&&color[u]==color[v])
                return false;
        }
    }
    return true;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,e,x,y;

    while(sif(n))
    {
        if(!n)
            break;

        sif(e);
        vector<int>g[n];

        for(int i=0;i<e;i++)
        {
            sf("%d%d", &x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }

        if(bipar(g, 0, n))
            pf("BICOLORABLE.\n");
        else
            pf("NOT BICOLORABLE.\n");
    }

    return 0;
}
