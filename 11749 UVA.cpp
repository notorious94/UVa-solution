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

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

class edge
{
public:
    int u,v;
    ll w;
    edge(int a,int b,ll c)
    {
        u = a,v = b,w = c;
    }
    bool operator < (const edge &p) const
    {
        return w > p.w;
    }
};

int p[501],r[501];
vector<edge>e;

void reset(int n)
{
    e.clear();
    for(int i=1;i<=n;i++)
    {
        p[i] = i;
        r[i] = 1;
    }
}

int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}

int makePair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u==v)    return -1;
    if(r[u]>=r[v])
    {
        r[u]+=r[v];
        p[v] = p[u];
        return r[u];
    }
    else
    {
        r[v]+=r[u];
        p[u] = p[v];
        return r[v];
    }
}

void input(int m)
{
    int a,b;
    ll c;
    while(m--)
    {
        scanf("%d%d%lld",&a,&b,&c);
        e.push_back(edge(a,b,c));
    }
    sort(all(e));
}

int Kruskal(int n)
{
    int ans = 0,c = 0;
    ll max_ppa = e[0].w;
    for(int i=0;i<e.size();i++)
    {
        int value = makePair(e[i].u,e[i].v);
        if(max_ppa==e[i].w)
            ans = max(ans,value);
        else    break;
    }
    return ans;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(!n&&!m)  break;
        reset(n);
        input(m);
        printf("%d\n",Kruskal(n));
    }
    return 0;
}
