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
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d",&n);
        int p, mile=0,juice=0;
        while(n--)
        {
            scanf("%d",&p);
            for(int i=0,pluse=0;pluse<p;i++)
            {
                (!pluse) ? pluse+=59 : pluse+=60;
                juice+=15;
            }
            for(int i=0,pluse=0;pluse<p;i++)
            {
                (!pluse) ? pluse+=29 : pluse+=30;
                mile+=10;
            }
        }
        if(mile==juice)
            printf("Case %d: Mile Juice %d\n",k,juice);
        else if(mile<juice)
            printf("Case %d: Mile %d\n",k,mile);
        else if(juice<mile)
            printf("Case %d: Juice %d\n",k,juice);
    }
    return 0;
}
