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

int p[27],r[27];

class E
{
public:
    int u,v,w;
    E(int a,int b,int c)
    {
        if(a>b) swap(a,b);
        u = a, v = b, w = c;
    }
    bool operator < (const E &p) const
    {
        if(w!=p.w)
            return w < p.w;
        if(u!=p.u)
            return u < p.u;
        return v < p.v;
    }
};
vector<E>edge;
bool grid[27][27];

void reset(int n)
{
    mem(grid,false);
    edge.clear();
    for(int i=0;i<n;i++)
    {
        p[i] = i;
        r[i] = 1;
    }
}

void input(int n)
{
    string s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>s;
            if(i==j)    continue;
            if(grid[i][j]||grid[j][i])
                continue;

            if(s[s.size()-1]==',')
                s.erase(s.size()-1);

            int w = atoi(s.c_str());
            if(!w)  continue;

            edge.push_back(E(i,j,w));
            grid[i][j] = grid[j][i] = true;
        }
    }
    sort(all(edge));
}

int Find(int a)
{
    return (a==p[a]) ?  a :  p[a] = Find(p[a]);
}

bool make_pair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u==v)    return false;
    if(r[u]>=r[v])
    {
        r[u]+=r[v];
        p[v] = p[u];
    }
    else
    {
        r[v]+=r[u];
        p[u] = p[v];
    }
    return true;
}

void Kruskal(int n)
{
    int c = 0;

    for(int i=0;i<edge.size();i++)
    {
        int a = edge[i].u;
        int b = edge[i].v;
        if(make_pair(a,b))
        {
            printf("%c-%c %d\n",a+'A',b+'A',edge[i].w);
            if(++c==n-1)    break;
        }
    }

}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t,n;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d",&n);
        reset(n);
        input(n);
        printf("Case %d:\n",k);
        Kruskal(n);
    }
    return 0;
}
