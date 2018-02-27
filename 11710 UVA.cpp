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


int p[401],r[401];

int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}

bool makePair(int a, int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u==v)    return false;
    if(r[u]>=r[v])
    {
        r[u]+=r[v];
        p[v] = u;
    }
    else
    {
        r[v]+=r[u];
        p[u] = v;
    }
    return true;
}

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        r[i] = 1;
        p[i] = i;
    }
}

class edge
{
public:
    int u,v,w;
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
    bool operator < (const edge &p) const{
        return w < p.w;
    }
};

vector<edge>edges;

int Kruskal(int n)
{
    sort(edges.begin(),edges.end());
    int connect = 0, sum = 0, limit = edges.size();
    bool possible = false;
    for(int i=0;i<limit;i++)
    {
        int x = edges[i].u;
        int y = edges[i].v;
        int c = edges[i].w;
        if(makePair(x,y))
        {
            sum+=c;
            if(++connect==n-1)
            {
                possible = true;
                break;
            }
        }
    }
    return (possible) ? sum : -1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,int>city;
    char u[20],v[20];
    int s,c,cost;
    while(scanf("%d%d",&s,&c))
    {
        if(!s && !c) break;

        edges.clear();
        city.clear();
        init(s);

        for(int i=1;i<=s;i++)
        {
            scanf("%s",u);
            city[u] = i;
        }

        while(c--)
        {
            scanf("%s%s%d",u,v,&cost);
            int x = city[u];
            int y = city[v];
            edges.push_back(edge(x,y,cost));
        }
        scanf("%s",u);

        if(s==1) // Corner Case -> Only one city
        {
            printf("0\n");
            continue;
        }

        int result = Kruskal(s);
        (result!=-1) ? printf("%d\n",result) : printf("Impossible\n");
    }
    return 0;
}
