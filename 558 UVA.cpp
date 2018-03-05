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
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

class edge{
public:
    int u,v,w;
    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};

int dist[1000];
vector<edge>e;

void init(int n)
{
    e.clear();
    for(int i=0;i<n;i++)
        dist[i] = INF;
}

void input(int m)
{
    int a,b,c;
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        e.push_back(edge(a,b,c));
    }
}

bool BellmanFord(int n)
{
    dist[0] = 0;
    for(int s=1;s<=n;s++)
    {
        bool update = false;
        for(int i=0;i<e.size();i++)
        {
            int u = e[i].u;
            int v = e[i].v;
            int w = e[i].w;
            if(dist[u]!=INF)
            {
                if(dist[u]+w<dist[v])
                {
                    dist[v] = dist[u]+w;
                    update = true;
                }
            }
        }
        if(update == true && s==n)
            return true;
        if(update == false)
            return false;
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init(n);
        input(m);
        (BellmanFord(n)) ? printf("possible\n") : printf("not possible\n");
    }

    return 0;
}
