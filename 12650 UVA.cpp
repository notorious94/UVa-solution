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

bool ID[10001];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,r,c;

    while(scanf("%d%d",&n,&r)!=EOF)
    {
        for(int i=1;i<=n;i++)
            ID[i] = false;

        for(int i=1;i<=r;i++)
        {
            scanf("%d",&c);
            ID[c] = true;
        }

        int limit = n-r;

        if(!limit)
        {
            pf("*\n");
            continue;
        }

        c = 0;

        for(int i=1;i<=n;i++)
        {
            if(ID[i]==false)
            {
                c++;
                pf("%d ",i);
                if(c==limit)  break;
            }
        }

        pf("\n");

    }

    return 0;
}
