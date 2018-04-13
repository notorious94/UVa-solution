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

class E{
public:
    int u,v;
    double w;
    E(int a, int b, double c){
        u = a,v = b,w = c;
    };
    bool operator < (const E &p) const {
        return  w < p.w;
    }
};

int p[505],r[505];
vector<E>edge;

void reset(int n)
{
    edge.clear();
    for(int i=0;i<=n;i++)
        p[i] = i,r[i] = 1;
}

void input(int m)
{
    double x,y;
    vector<pdd>coord;
    for(int i=0;i<m;i++)
    {
        scanf("%lf%lf",&x,&y);
        coord.push_back(pdd(x,y));
    }
    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            double x1 = coord[i].first;
            double x2 = coord[j].first;
            double y1 = coord[i].second;
            double y2 = coord[j].second;
            edge.push_back(E(i,j,_distance(x1,y1,x2,y2)));
        }
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

void Kruskal(int s,int n)
{
    int e = 0;
    vector<double>ans_set;
    for(int i=0;i<edge.size();i++)
        if(makePair(edge[i].u,edge[i].v))
        {
            ans_set.push_back(edge[i].w);
            if(++e==n-1)    break;
        }
    sort(all(ans_set));
    printf("%.2lf\n",sqrt(ans_set[e-s]));
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,s,p;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d%d",&s,&p);
        reset(p);
        input(p);
        Kruskal(s,p);
    }
    return 0;
}
