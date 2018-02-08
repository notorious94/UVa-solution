#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int level[1000];
vector<int>adj[1000];
bool visit[1000];

void reset(int p)
{
    for(int i=0;i<p;i++)
    {
        visit[i] = false;
        adj[i].clear();
    }
}

void input(int d)
{
    int a,b;
    while(d--)
    {
        sf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void BFS(int s, int p)
{
    queue<int>q;
    q.push(0);
    level[0] = 0;
    visit[0] = true;
    p--;
    while(q.size() && p)
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(visit[v]==false)
            {
                visit[v] = true;
                p--;
                level[v] = 1+level[u];
                q.push(v);
            }
        }
    }
}

void print(int p)
{
    for(int i=1;i<p;i++)
        pif(level[i]);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,p,d;
    scanf("%d",&t);
    while(t--)
    {
        sf("%d%d",&p,&d);
        reset(p);
        input(d);
        BFS(0,p);
        print(p);
        if(t)   puts("");
    }

    return 0;
}
