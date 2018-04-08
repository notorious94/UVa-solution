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
    return (x1x2*x1x2)+(y1y2*y1y2);
}

class E
{
public:
    int u,v;
    double w;
    E(int a,int b,double c){
        u = a, v = b, w = c;
    }
    bool operator <(const E &p) const{
        return w < p.w;
    }
};

int p[205],r[205];
vector<E>edge;

void reset(int n)
{
    edge.clear();
    for(int i=0;i<n;i++)
        p[i] = i, r[i] = 1;
}

int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}

bool makePair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u!=v)
    {
        if(r[u]>=r[v])  p[v] = p[u] , r[u]+=r[v];
        else            p[u] = p[v] , r[v]+=r[u];
        return true;
    }
    return false;
}

void Kruskal(int n)
{
    double e = -INF;
    for(int i=0;i<edge.size();i++)
        if(makePair(edge[i].u,edge[i].v))
        {
            e = max(sqrt(edge[i].w),e);
            if(Find(0)==Find(1))
            {
                printf("Frog Distance = %0.3lf\n\n",e);
                return;
            }
        }
}

void input(int n)
{
    double x,y;
    vector<pdd>coord;
    while(n--)
    {
        scanf("%lf%lf",&x,&y);
        coord.push_back(pdd(x,y));
    }
    for(int i=0;i<coord.size()-1;i++)
        for(int j=i+1;j<coord.size();j++)
            edge.push_back(E(i,j,_distance(coord[i].first,coord[j].second,coord[j].first,coord[i].second)));
    sort(all(edge));
    Kruskal(coord.size());
    coord.clear();
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int n,k,m,kase = 0;
    double x = 3.14;

    while(scanf("%d",&n)==1)
    {
        if(!n)  break;
        reset(n);
        printf("Scenario #%d\n",++kase);
        input(n);
    }
    return 0;
}
