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
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

vector<int>g[2001],t[2001],top,temp;
bool visit[2001];

void init(int n)
{
    top.clear();
    temp.clear();
    mem(visit,false);
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
        t[i].clear();
    }
}

void edge(int m)
{
    int u,v,w;
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(w==1)
        {
            g[u].push_back(v);
            t[v].push_back(u);
        }
        else
        {
            g[u].push_back(v);
            g[v].push_back(u);

            t[u].push_back(v);
            t[v].push_back(u);
        }
    }
}

void DFS_1(int s)
{
    visit[s] = true;
    for(int i=0;i<g[s].size();i++)
        if(!visit[g[s][i]])
            DFS_1(g[s][i]);
    top.push_back(s);
}

void call_1(int n)
{
    for(int i=1;i<=n;i++)
        if(!visit[i])
            DFS_1(i);
}

void DFS_2(int s)
{
    visit[s] = true;
    for(int i=0;i<t[s].size();i++)
        if(!visit[t[s][i]])
            DFS_2(t[s][i]);
}

bool call_2(int n)
{
    mem(visit,false);
    int scc = 0;
    for(int i=top.size()-1;i>=0;i--)
        if(!visit[top[i]])
        {
            if(++scc>1) return false;
            DFS_2(top[i]);
        }
    return true;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(!n&&!m)  break;
        init(n);
        edge(m);
        call_1(n);
        if(call_2(n))
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
