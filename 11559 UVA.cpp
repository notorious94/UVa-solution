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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,b,h,w,p,a,cost;

    while(scanf("%d%d%d%d",&n,&b,&h,&w)!=EOF)
    {
        cost = INF;
        for(int i=1;i<=h;i++)
        {
            scanf("%d",&p);
            for(int j=1;j<=w;j++)
            {
                scanf("%d",&a);
                if(n<=a&&p*n<=b)    cost = min(cost,p*n);
            }
        }
        (cost == INF) ? pf("stay home\n") : pf("%d\n",cost);
    }

    return 0;
}
