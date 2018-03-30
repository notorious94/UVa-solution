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

class E
{
public:
    int x,y,w;
    E(int a, int b, int c)
    {
        x = a;
        y = b;
        w = c;
    }
    bool operator < (const E &p) const
    {
        return w > p.w;
    }
};

int p[201],r[201];
map<string,int>id;
vector<E>edge;

void reset(int n)
{
    id.clear();
    edge.clear();
    for(int i=1;i<=n;i++)
    {
        p[i] = i;
        r[i] = i;
    }
}

int Find(int a)
{
    return (a==p[a]) ? a : p[a]=Find(p[a]);
}

bool makePair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u==v)    return false;
    if(r[u]>=r[v])
    {
        r[u]+=r[v];
        p[v]=p[u];
    }
    else
    {
        r[v]+=r[u];
        p[u]=p[v];
    }
    return true;
}

int Kruskal(int s,int d)
{
    int min_cost = INF;
    sort(all(edge));
    for(int i=0;i<edge.size();i++)
        if(makePair(edge[i].x,edge[i].y))
        {
            min_cost = min(min_cost,edge[i].w);
            if(Find(s)==Find(d))    break;
        }
    printf("%d tons\n\n",min_cost);
}

void input(int r)
{
    int i=1,c,a,b;
    char u[50],v[50];

    while(r--)
    {
        scanf("%s%s%d",u,v,&c);
        a = id[u];
        b = id[v];

        if(!a)
        {
            id[u] = i++;
            a = i-1;
        }

        if(!b)
        {
            id[v] = i++;
            b = i-1;
        }
        edge.push_back(E(a,b,c));
    }

    scanf("%s%s",u,v);
    int s = id[u];
    int d = id[v];
    Kruskal(s,d);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,r,kase = 0;
    while(scanf("%d%d",&n,&r))
    {
        if(!n&&!r)  break;
        printf("Scenario #%d\n",++kase);
        reset(n);
        input(r);
    }
    return 0;
}
