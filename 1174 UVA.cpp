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

class e
{
public:
    int u,v,w;
    e(int a,int b,int c){
        u = a,v = b,w = c;
    }
    bool operator < (const e &p) const{
        return w < p.w;
    }
};

vector<e>edge;
int p[2001],r[2001];
map<string,int>id;

void reset(int n)
{
    edge.clear();
    id.clear();
    for(int i=1;i<=n;i++)
        p[i] = i,r[i] = 1;
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
    if(r[u]>=r[v])  p[v] = p[u], r[u]+=r[v];
    else            p[u] = p[v], r[v]+=r[u];
    return true;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t,n,m,cost;
    char city1[500],city2[500];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        reset(n);

        int mst = 0,c = 0,i = 1;

        while(m--)
        {
            scanf("%s%s%d",city1,city2,&cost);
            int a = id[city1];
            int b = id[city2];
            if(!a)  a = id[city1] = i++;
            if(!b)  b = id[city2] = i++;
            edge.push_back(e(a,b,cost));
        }

        sort(all(edge));

        for(int i=0;i<edge.size();i++)
            if(make_pair(edge[i].u,edge[i].v))
            {
                mst+=edge[i].w;
                if(++c==n-1)    break;
            }

        pif(mst);

        if(t)   puts("");

    }
    return 0;
}
