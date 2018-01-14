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

int Rank[30001],Parent[30001];

void reset(int n)
{
    for(int i=0;i<=n;i++)
    {
        Rank[i] = 1;
        Parent[i] = i;
    }
}

int find_parent(int n)
{
    return (n==Parent[n]) ? n : Parent[n] = find_parent(Parent[n]);
}

void make_pair(int a,int b)
{
    int u = find_parent(a);
    int v = find_parent(b);

    if(u==v)    return;

    if(Rank[u]>=Rank[v])
    {
        Parent[v] = u;
        Rank[u]+=Rank[v];
    }

    else
    {
        Parent[u] = v;
        Rank[v]+=Rank[u];
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k,p,q;

    while(scanf("%d%d",&n,&m))
    {
        if(!n && !m)    break;

        reset(n);

        while(m--)
        {
            scanf("%d",&k);

            for(int i=0;i<k;i++)
            {
                scanf("%d",&q);
                if(!i)  p = q;
                make_pair(p,q);
            }
        }

        int suspect = Rank[find_parent(0)];
        pf("%d\n",suspect);
    }
    return 0;
}
