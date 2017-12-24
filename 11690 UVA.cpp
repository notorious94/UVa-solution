#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int p[10000],sum[10000],r[10000];

int Find(int x)
{
    return (p[x]==x) ? x : p[x] = Find(p[x]);
}

void makeUnion(int x, int y)
{
    int u = Find(x);
    int v = Find(y);

    if(u==v)    return;

    if(r[u]>=r[v])
    {
        p[v] = u;
        sum[u] += sum[v];
        r[u] += r[v];
    }

    else
    {
        p[u] = v;
        sum[v] += sum[u];
        r[v] += r[u];
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,m,o,x,y;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);

        for(int i=0;i<n;i++)
        {
            scanf("%d",&o);
            p[i] = i;
            r[i] = 1;
            sum[i] = o;
        }

        while(m--)
        {
            scanf("%d%d",&x,&y);
            makeUnion(x,y);
        }

        bool flag = true;

        for(int i=0;i<n;i++)
        {
            if(sum[Find(p[i])])
            {
                flag = false;
                break;
            }
        }

        if(flag)
            pf("POSSIBLE\n");
        else
            pf("IMPOSSIBLE\n");
    }

    return 0;
}
