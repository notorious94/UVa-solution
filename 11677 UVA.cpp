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

    int h1,m1,h2,m2;
    int t1, t2, r;

    while(scanf("%d%d%d%d",&h1,&m1,&h2,&m2))
    {
        if(!h1&&!m1&&!h2&&!m2)  break;

        t1 = h1*60 + m1;
        t2 = h2*60 + m2;

        r = t2 - t1;

        if(r<0) r += 1440;

        pif(r);
    }

    return 0;
}
