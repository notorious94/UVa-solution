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

typedef long long ll;
typedef unsigned long long ull;

ll bigmod(int p,int m)
{
    if(!p)  return 1%m;
    if(p&1) return (10%m*bigmod(p-1,m)%m);
    else
    {
        ll left = bigmod(p/2,m)%m;
        return (left*left)%m;
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(scanf("%d",&n)==1)
    {
        int len=1,t = n;
        if(n==1)
        {
            pif(n);
            continue;
        }
        bool div = false;
        while(!div)
        {
            ll r = 0;
            for(int i=0;i<=len;i++)
            {
                r+=bigmod(i,n);
                r%=n;
                if(!r){
                    pif(len+1);
                    div = true;
                    break;
                }
                else if(i==len&&r){
                    len++;
                }
            }
        }

    }
    return 0;
}
