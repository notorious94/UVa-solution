#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
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

    int r,n,c,cn=0,d;

    while(scanf("%d%d",&r,&n))
    {
        if(!r&&!n)  break;
        cn++;
        printf("Case %d: ",cn);

        if(n>=r)
        {
            printf("0\n");
            continue;
        }

        c=0;
        d = n;
        bool p = false;

        for(int i=1;i<=26;i++)
        {
            n+=d;
            c++;
            if(n>=r)
            {
                p=true;
                break;
            }
        }

        if(p)
            printf("%d\n",c);
        else
            printf("impossible\n");

    }
    return 0;
}
