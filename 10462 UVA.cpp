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

class E{
public:
    int u,v,w;
    E(int a,int b,int c){
        u = a,v = b,w = c;
    }
    bool operator < (const E &p){
        return w < p.w;
    }
};

int p[105],r[105];
vector<E>edge;

void reset(int n)
{
    for(int i=1;i<=n;i++)
        p[i] = i,r[i] = 1;
}

int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}

bool makePair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u!=v)    {
        if(r[u]>=r[v]) p[v] = p[u] , r[u]+=r[v];
        else           p[u] = p[v] , r[v]+=r[u];
        return true;
    }
    return false;
}

void input(int e)
{
    int a,b,c;
    while(e--)
    {
        scanf("%d%d%d",&a,&b,&c);
        edge.push_back(E(a,b,c));
    }
}

void Kruskal(int n)
{
    int e1 = 0,sum1 = 0;
    if(e1==n-1) // If N = 1 and No edge
    {
        printf("No second way\n");
        return;
    }
    bool MST = false;
    vector<int>selected;
    sort(all(edge));
    for(int i=0;i<edge.size();i++)
        if(makePair(edge[i].u,edge[i].v))
        {
            sum1+=edge[i].w;
            selected.push_back(i);
            if(++e1==n-1)
            {
                MST = true;
                break;
            }
        }

    if(!MST)
    {
        printf("No way\n");
        return;
    }
    MST = false;
    int SUM = INF;
    for(int i=0;i<selected.size();i++)
    {
        reset(n);
        int sum = 0,e = 0;
        for(int j=0;j<edge.size();j++)
        {
            if(j!=selected[i])
            {
                if(makePair(edge[j].u,edge[j].v))
                {
                    sum += edge[j].w;
                    if(++e==n-1)
                    {
                        MST = true;
                        SUM = min(SUM,sum);
                        break;
                    }
                }
            }
        }
    }
    if(MST==false)
    {
        printf("No second way\n");
        return;
    }
    else
        printf("%d\n",SUM);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e,t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&e);
        reset(n);
        edge.clear();
        input(e);
        printf("Case #%d : ",i);
        Kruskal(n);
    }

    return 0;
}
