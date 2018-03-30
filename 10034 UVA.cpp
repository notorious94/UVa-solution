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

class edge
{
public:
    int x,y;
    double dist;
    edge(int a,int b,double d)
    {
        x = a;
        y = b;
        dist = d;
    }
    bool operator < (const edge &p) const
    {
        return dist < p.dist;
    }
};

int p[101],r[101];
vector<edge>e;

void reset(int n)
{
    e.clear();
    for(int i=0; i<=n; i++)
    {
        p[i] = i;
        r[i] = 1;
    }
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
    {
        r[u] += r[v];
        p[v] = p[u];
    }
    else
    {
        r[v] += r[u];
        p[u] = p[v];
    }
    return true;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return (x1x2*x1x2)+(y1y2*y1y2);
}

void input(int n)
{
    double x,y;
    vector<pdd>c;
    for(int i=0; i<n; i++)
    {
        scanf("%lf%lf",&x,&y);
        c.push_back(pdd(x,y));
    }
    int l = n-1;
    for(int i=0;i<l;i++)
        for(int j=i+1;j<n;j++)
        {
            double x1 = c[i].first;
            double y1 = c[i].second;
            double x2 = c[j].first;
            double y2 = c[j].second;
            e.push_back(edge(i,j,_distance(x1,y1,x2,y2)));
        }
}

void Kruskal(int n,int test)
{
    int E = 0;
    double sum = 0;

    sort(all(e));

    for(int i=0;i<e.size();i++)
    {
        int u = e[i].x;
        int v = e[i].y;
        if(makePair(u,v))
        {
            sum+=sqrt(e[i].dist);
            if(++E==n)    break;
        }
    }

    printf("%.2lf\n",sum);
    if(test)    puts("");
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test,n;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&n);
        reset(n);
        input(n);
        Kruskal(--n,test);
    }

    return 0;
}
