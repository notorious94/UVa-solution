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
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

class edge{
public:
    int u,v,w;
    edge(int a, int b, int c){
        u = a;
        v = b;
        w = c;
    };
    bool operator < (const edge &p) const {
        return  w < p.w;
    }
};

int money,p[200000],r[200000];
vector<edge>edgeList;

void init(int n)
{
    edgeList.clear();
    money = 0;
    for(int i=0;i<n;i++)
    {
        p[i] = i;
        r[i] = 1;
    }
}

void input(int m)
{
    int x,y,z;
    while(m--)
    {
        scanf("%d%d%d",&x,&y,&z);
        money+=z;
        edgeList.push_back(edge(x,y,z));
    }
}

int Find(int a)
{
    return (p[a]==a) ? a : p[a] = Find(p[a]);
}

bool makePair(int a, int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u==v)    return false;
    if(r[u]>=r[v])
    {
        p[v] = u;
        r[u] += r[v];
    }
    else
    {
        p[u] = v;
        r[v] += r[u];
    }
    return true;
}

void Kruskal(int n, int m)
{
    sort(edgeList.begin(),edgeList.end());
    for(int i=0,c = 0;i<m;i++)
    {
        int a = edgeList[i].u;
        int b = edgeList[i].v;
        if(makePair(a,b))
        {
            money-=edgeList[i].w;
            c++;
            if(c==n-1)  break;
        }
    }
    printf("%d\n",money);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(!n && !m)    break;
        init(n);
        input(m);
        Kruskal(n,m);
    }
    return 0;
}
