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

class E{
public:
    int u,v,w;
    E(int a, int b, int c){
        u = a,v = b,w = c;
    };
    bool operator < (const E &p) const {
        return  w > p.w;
    }
};

int p[105],r[105];
vector<E>edge;

void reset(int n)
{
    edge.clear();
    for(int i=0;i<n;i++)
        p[i] = i,r[i] = 1;
}

void input(int m)
{
    int x,y,z;
    while(m--)
    {
        scanf("%d%d%d",&x,&y,&z);
        edge.push_back(E(x,y,z));
    }
    sort(all(edge));
}

int Find(int a)
{
    return (p[a] == a) ? a : p[a] = Find(p[a]);
}

bool makePair(int a, int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u==v)    return false;
    if(r[u]>=r[v])  p[v] = u,r[u] += r[v];
    else            p[u] = v,r[v] += r[u];
    return true;
}

int Kruskal(int n)
{
    int min_Cost = INF, e = 0;
    for(int i=0;i<edge.size();i++)
        if(makePair(edge[i].u,edge[i].v))
        {
            min_Cost =min(min_Cost,edge[i].w);
            if(++e==n-1)  return min_Cost;
        }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d%d",&n,&m);
        reset(n);
        input(m);
        printf("Case #%d: %d\n",k,Kruskal(n));
    }
    return 0;
}
