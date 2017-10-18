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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,v;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int max = -1, min = 99999;

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v);
            if(v>max)   max = v;
            if(min>v)   min = v;
        }
        int ans = max-min;
        ans+=ans;
        printf("%d\n",ans);
    }

    return 0;
}
