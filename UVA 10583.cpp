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

int p[50001];
int Find(int a)
{
    if(p[a]==a) return a;
    return Find(p[a]);
}

bool makeUnion(int a, int b)
{
    int x = Find(a);
    int y = Find(b);
    if(x==y)    return false;
    p[y] = x;
    return true;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,kase = 0;
    while(sf("%d%d",&n,&m))
    {
        if(!n&&!m)  break;
        kase++;
        pf("Case %d: ",kase);
        for(int i=1;i<=n;i++)
            p[i] = i;
        int ans = n,a,b;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            if(makeUnion(a,b))  ans--;
        }
        pif(ans);
    }
    return 0;
}
