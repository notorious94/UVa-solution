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
    int u,v,w;
    edge(int a,int b,int c)
    {
        u = a,v = b,w = c;
    }
    bool operator < (const edge &p) const
    {
        return w < p.w;
    }
};

int p[3001],r[3001];
vector<edge>e;

void reset(int n)
{
    for(int i=1;i<=n;i++)
        p[i] = i,r[i] = 1;
}

void input(int r)
{
    e.clear();
    int a,b,l;
    while(r--)
    {
        scanf("%d%d%d",&a,&b,&l);
        e.push_back(edge(a,b,l));
    }
    sort(all(e));
}

int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}

bool makePair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u==v)    return false;
    if(r[u]>=r[v])
        p[v] = p[u] , r[u] += r[v];
    else
        p[u] = p[v] , r[v] += r[u];
    return true;
}

void Kruskal(int n,int s,int d)
{
    reset(n);
    int ans = 0;
    bool flag = false;
    for(int i=0;i<e.size();i++)
    {
        int a = e[i].u;
        int b = e[i].v;
        if(makePair(a,b))
        {
            if(a==s||a==d||b==s||b==d)
                flag = true;
            if(flag)    ans = max(ans,e[i].w);
            if(Find(s)==Find(d))    break;
        }
    }
    pif(ans);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,r,q,s,d;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d%d",&n,&r);
        input(r);
        printf("Case %d\n",k);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&s,&d);
            Kruskal(n,s,d);
        }
        puts("");
    }
    return 0;
}
