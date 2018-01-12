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


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int b,s,kase = 0,age;

    while(scanf("%d%d",&b,&s))
    {
        if(!b&&!s)  break;

        int left = b-s;
        int young_bachelor = INF;

        while(b--)
        {
            scanf("%d",&age);
            young_bachelor = min(young_bachelor,age);
        }

        while(s--)
            scanf("%d",&age);

        if(left>0)
            pf("Case %d: %d %d\n",++kase,left,young_bachelor);
        else
            pf("Case %d: 0\n",++kase);

    }

    return 0;
}
