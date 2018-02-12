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

class edge
{
public:
    int u,v,w;
    edge(int p, int q, int r){
        u = p;
        v = q;
        w = r;
    }
    bool operator < (const edge &p)const {
        return  w < p.w;
    }
};

int p[1001], r[1001];
vector<edge>edgeList;

void init(int n)
{
    edgeList.clear();
    for(int i=0;i<=n;i++)
    {
        p[i] = i;
        r[i] = 1;
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

void input(int m)
{
    int u,v,w;
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&w);
        edgeList.push_back(edge(u,v,w));
    }
}

void Kruskal(int n, int m)
{
    sort(edgeList.begin(),edgeList.end());
    vector<bool>validEdge(m,true);
    int count = 0;
    for(int i=0;i<edgeList.size();i++)
    {
        int a = edgeList[i].u;
        int b = edgeList[i].v;
        if(makePair(a,b)){
            count++;
            validEdge[i] = false;
            if(count==n-1)  break;
        }
    }

    if(count==m)
    {
        pf("forest\n");
        return;
    }

    else
    {
        vector<int>temp;
        for(int i=0;i<m;i++)
            if(validEdge[i])
                temp.push_back(edgeList[i].w);
        for(int i=0;i<temp.size()-1;i++)
            pf("%d ",temp[i]);
        pf("%d\n",temp.back());
    }

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
        if(!n&&!m)  break;
        init(n);
        input(m);
        Kruskal(n,m);
    }
    return 0;
}
