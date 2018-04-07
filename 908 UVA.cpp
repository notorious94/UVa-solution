#include<bits/stdc++.h>
#include<unordered_map>
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

class E
{
public:
    int u,v,w;
    E(int a,int b,int c){
        u = a, v = b, w = c;
    }
    bool operator <(const E &p) const{
        return w < p.w;
    }
};

int p[100005],r[100005];
vector<E>edge;

void reset(int n)
{
    edge.clear();
    for(int i=1;i<=n;i++)
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

int Kruskal(int n)
{
    int sum = 0,e = 0;
    for(int i=0;i<edge.size();i++)
        if(makePair(edge[i].u,edge[i].v))
        {
            sum+=edge[i].w;
            if(++e==n-1)
                return sum;
        }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int n,k,m,kase = 0;
    while(scanf("%d",&n)==1)
    {
        if(++kase>1)    puts("");
        reset(n);
        int prev = 0;
        int a,b,c;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            edge.push_back(E(a,b,c));
            prev+=c;
        }
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d%d%d",&a,&b,&c);
            edge.push_back(E(a,b,c));
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            edge.push_back(E(a,b,c));
        }
        sort(all(edge));
        printf("%d\n",prev);
        printf("%d\n",Kruskal(n));
    }
    return 0;
}
