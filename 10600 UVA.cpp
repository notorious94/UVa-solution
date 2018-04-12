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
        u = a;
        v = b;
        w = c;
    };
    bool operator < (const E &p) const {
        return  w < p.w;
    }
};

vector<E>edge;
int p[105],r[105];

void reset(int n)
{
    for(int i=1;i<=n;i++)
        p[i] = i,r[i] = 1;
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

void Kruskal(int n)
{
    int e = 0,best,secondBest=INF,sum = 0;
    vector<int>selected;

    for(int i=0;i<edge.size();i++)
        if(makePair(edge[i].u,edge[i].v))
        {
            selected.push_back(i);
            sum+=edge[i].w;
            if(++e==n-1)
            {
                best = sum;
                break;
            }
        }

    for(int i=0;i<selected.size();i++)
    {
        reset(n);
        sum = 0,e = 0;
        for(int j=0;j<edge.size();j++)
        {
            if(j==selected[i])  continue;
            if(makePair(edge[j].u,edge[j].v))
            {
                sum+=edge[j].w;
                if(++e==n-1)
                {
                    secondBest=min(sum,secondBest);
                    break;
                }
            }
        }

    }
    printf("%d %d\n",best,secondBest);
}

void input(int m)
{
    int a,b,c;
    edge.clear();
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        edge.push_back(E(a,b,c));
    }
    sort(all(edge));
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        reset(n);
        input(m);
        Kruskal(n);
    }
    return 0;
}
