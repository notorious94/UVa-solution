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

    ull fib[52] = {1,2};

    for(int i=2;i<52;i++)
        fib[i] = fib[i-1] + fib[i-2];

    int n,c;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c);
        printf("Scenario #%d:\n",i);
        printf("%llu\n\n",fib[c]);
    }

    return 0;
}
