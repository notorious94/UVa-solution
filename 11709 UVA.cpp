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
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

map<string,int>ID;
vector<int>top,G[1001],T[1001];
bool visit[1001];

void init(int n)
{
    ID.clear();
    top.clear();
    for(int i=1;i<=n;i++)
        G[i].clear(),T[i].clear(),visit[i] = false;
}

void input(int n,int e)
{
    char u[500],v[500];
    for(int i=1;i<=n;i++)
    {
        gets(u);
        ID[u] = i;
    }
    while(e--)
    {
        gets(u);
        gets(v);
        int a = ID[u];
        int b = ID[v];
        G[a].push_back(b);
        T[b].push_back(a);
    }
    ID.clear();
}

void DFS1(int s)
{
    visit[s] = true;
    for(int i=0;i<G[s].size();i++)
        if(!visit[G[s][i]])
            DFS1(G[s][i]);
    top.push_back(s);
}

void callOne(int n)
{
    for(int i=1;i<=n;i++)
        if(!visit[i])
            DFS1(i);
}

void DFS2(int s)
{
    visit[s] = true;
    for(int i=0;i<T[s].size();i++)
        if(!visit[T[s][i]])
            DFS2(T[s][i]);
    top.push_back(s);
}

void callTwo(int n)
{
    int scc = 0;
    mem(visit,false);
    for(int i=n-1;i>=0;i--)
        if(!visit[top[i]])
        {
            DFS2(top[i]);
            scc++;
        }
    printf("%d\n",scc);
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,e;
    while(scanf("%d%d",&n,&e))
    {
        if(!n&&!e)  break;
        getc(stdin);
        init(n);
        input(n,e);
        callOne(n);
        callTwo(n);
    }
    return 0;
}
