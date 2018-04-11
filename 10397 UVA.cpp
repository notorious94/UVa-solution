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
    double dist;
    E(int a,int b,double c)
    {
        u = a, v = b, dist = c;
    }
    bool operator < (const E &p) const
    {
        return dist < p.dist;
    }
};

int p[755],r[755];

vector<E>edge;

void reset(int n)
{
    edge.clear();
    for(int i=1;i<=n;i++)
        p[i]=i,r[i]=1;
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
        if(r[u]>=r[v]) p[v]=p[u],r[u]+=r[v];
        else           p[u]=p[v],r[v]+=r[u];
        return true;
    }
    return false;
}

void input(int n)
{
    vector<pdd>c;
    double x,y;

    while(n--)
    {
        scanf("%lf%lf",&x,&y);
        c.push_back(pdd(x,y));
    }

    for(int i=0;i<c.size()-1;i++)
        for(int j=i+1;j<c.size();j++)
        {
            double x1 = c[i].first;
            double x2 = c[j].first;
            double y1 = c[i].second;
            double y2 = c[j].second;
            edge.push_back(E(i+1,j+1,_distance(x1,y1,x2,y2)));
        }
}
void Kruskal(int m,int n)
{
    int a,b,e = 0;
    double cable = 0.0;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        if(makePair(a,b))   e++;
    }
    sort(all(edge));
    for(int i=0;i<edge.size();i++)
    {
        if(makePair(edge[i].u,edge[i].v))
        {
            cable+=sqrt(edge[i].dist);
            if(++e==n-1)
                break;
        }
    }
    printf("%0.2lf\n",cable);
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while(scanf("%d",&n)==1)
    {
        reset(n);
        input(n);
        scanf("%d",&m);
        Kruskal(m,n);
    }
    return 0;
}
