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

int dx[]={-1,1,0,0,-1,1,-1,1};
int dy[]={0,0,-1,1,1,-1,-1,1};
int dz[]={0,0,1,-1,-1,1,-1,1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

int _distance(int x1,int y1,int x2,int y2)
{
    int x1x2 = x1 - x2;
    int y1y2 = y1 - y2;
    return (x1x2*x1x2)+(y1y2*y1y2);
}

class E
{
public:
    int u,v,d;
    E(int a,int b,int dist)
    {
        u=a,v=b,d=dist;
    }
    bool operator < (const E &p) const
    {
        return d < p.d;
    }
};

vector<E>edge;
int p[1000],r[1000];

void reset(int n)
{
    edge.clear();
    for(int i=1;i<=n;i++)
        p[i] = i, r[i] = 1;
}

void input(int n)
{
    vector<pii>coord;
    int x,y;
    while(n--)
    {
        scanf("%d%d",&x,&y);
        coord.push_back(pii(x,y));
    }
    for(int i=0;i<coord.size()-1;i++)
        for(int j=i+1;j<coord.size();j++)
            edge.push_back(E(i+1,j+1,_distance(coord[i].first,coord[i].second,coord[j].first,coord[j].second)));
    coord.clear();
}

int Find(int a)
{
    return(a==p[a]) ? a : p[a] = Find(p[a]);
}

bool makePair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u!=v)
    {
        if(r[u]>=r[v])  p[v] = p[u],r[u]+=r[v];
        else            p[u] = p[v],r[v]+=r[u];
        return true;
    }
    return false;
}

void Kruskal(int n)
{
    int m,e=0,a,b;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        if(makePair(a,b))   e++;
    }
    if(e==n-1)
    {
        printf("No new highways need.\n");
        return;
    }
    sort(all(edge));
    for(int i=0;i<edge.size();i++)
        if(makePair(edge[i].u,edge[i].v))
        {
            printf("%d %d\n",edge[i].u,edge[i].v);
            if(++e==n-1)    return;
        }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        reset(n);
        input(n);
        Kruskal(n);
        if(t)   puts("");
    }

    return 0;
}
