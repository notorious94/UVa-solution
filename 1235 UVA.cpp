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

class e
{
public:
    int u,v,w;
    e(int a,int b,int c)
    {
        u = a,v = b,w = c;
    }
    bool operator < (const e &p) const
    {
        return w < p.w;
    }
};

int p[501],r[501];
vector<e>edge;

void reset(int n)
{
    edge.clear();
    for(int i=0;i<=n;i++)
        p[i] = i, r[i] = 1;
}

int min_dist(int a,int b)
{
    int diff = abs(a-b);
    return min(10-diff,diff);
}

int input(int n)
{
    char lock[5];
    vector<string>locks;

    for(int i=0;i<n;i++)
    {
        scanf("%s",lock);
        locks.push_back(lock);
    }

    int mst = INF;

    for(int i=0;i<n;i++)
    {
        int sum = 0;
        for(int j=0;j<4;j++)
            sum+= min_dist(0,locks[i][j]-'0');
        mst = min(mst, sum);
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum = 0;
            for(int k=0;k<4;k++)
                sum += min_dist(locks[i][k]-'0',locks[j][k]-'0');
            edge.push_back(e(i,j,sum));
        }
    }

    locks.clear();
    sort(all(edge));

    return mst;
}

int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}

bool make_pair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u==v)    return false;
    if(r[u]>=r[v])
        p[v]=p[u],r[u]+=r[v];
    else
        p[u]=p[v],r[v]+=r[u];
    return true;
}

void Kruskal(int mst,int n)
{
    int connect = 1;
    for(int i=0;i<edge.size();i++)
        if(make_pair(edge[i].u,edge[i].v))
        {
            mst += edge[i].w;
            if(++connect==n)    break;
        }
    printf("%d\n",mst);
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
        int mst = input(n);
        Kruskal(mst,n);
    }
    return 0;
}
