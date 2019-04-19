#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define p_b push_back
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >

typedef long long ll;
typedef unsigned long long ull;

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};
int kx[]= {2,2,-2,-2,1,-1,1,-1};
int ky[]= {1,-1,1,-1,2,2,-2,-2};

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

/*
int lp[32001];
vector<int>prime;
void sieve(int limit = 32001)
{
    for(int i=2;i<limit;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&i*prime[j]<limit;j++)
            lp[i*prime[j]]=i;
    }
}
*/

vector<int>adj[100];
int t = 0, cut_p = 0, disc[100],low[100],parent[100];
bool visit[100],ap[100];

void reset(int n)
{
    cut_p = t = 0;
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        parent[i] = -1;
        visit[i] = ap[i] = false;
    }
}

void dfs(int u)
{
    int child = 0;
    visit[u] = true;
    disc[u] = low[u] = ++t;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(visit[v]==false)
        {
            child++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if(!ap[u]&&child>1&&parent[u]==-1)
                ap[u] = true,cut_p++;
            else if(!ap[u]&&parent[u]!=-1&&disc[u]<=low[v])
                ap[u] = true,cut_p++;
        }
        else if(v!=parent[u])
            low[u] = min(low[u],disc[v]);
    }
}

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n,u,v;
    string line;

    while(scanf("%d\n",&n))
    {
        if(!n)    break;
        reset(n);
        while(true)
        {
            getline(cin,line);
            stringstream ss(line);
            ss>>u;
            if(u==0)    break;
            while(ss>>v)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        for(int i=1;i<=n;i++)
            if(visit[i]==false)
                dfs(i);
        cout<<cut_p<<endl;
    }
    return 0;
}
