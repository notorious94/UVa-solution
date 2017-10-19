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
    ll s,d,a,b,t;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&s,&d);

        a = (s-d)/2;
        b = (s-a);

        if(b<0||a<0||(a+b)!=s||abs(a-b)!=d)
            printf("impossible\n");
        else
        {
            if(a<b) swap(a,b);
            printf("%lld %lld\n",a,b);
        }
    }
    return 0;
}
