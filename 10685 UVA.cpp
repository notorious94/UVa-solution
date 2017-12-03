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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int R[5001],p[5001];

int Find(int a)
{
    if(p[a]==a) return a;
    return Find(p[a]);
}

int makeUnion(int a, int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u==v)    return R[u];
    if(R[u]>=R[v])
    {
        R[u] += R[v];
        p[v] = u;
        return R[u];
    }
    else
    {
        R[v] += R[u];
        p[u] = v;
        return R[v];
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c,r;

    while(sf("%d%d",&c,&r))
    {
        if(!c&&!r)  break;
        for(int i=0;i<=c;i++)
        {
            p[i] = i;
            R[i] = 1;
        }

        int M = 1;
        char a[500],b[500];
        map<string, int>herb;

        for(int i=0;i<c;i++)
        {
            scanf("%s",a);
            herb[a] = i;
        }

        while(r--)
        {
            scanf("%s%s",a,b);
            M = max(M, makeUnion(herb[a], herb[b]));
        }

        pif(M);
        herb.clear();
    }
    return 0;
}
