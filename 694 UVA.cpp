#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int digitsum[1001];


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,limit,case_id=0;

    while(sf("%lld%lld", &n,&limit))
    {
        if(n<0&&limit<0)
            break;

        case_id++;

        pf("Case %lld: A = %lld, limit = %lld, number of terms = ",case_id,n,limit);

        ull terms=1;

        while(1)
        {
            if(n==1)
                break;
            else if(n>limit)
            {
                --terms;
                break;
            }

            if(n&1)
                n = 3*n+1;
            else
                n/=2;

            terms++;
        }
        printf("%lld\n",terms);

    }
    return 0;
}
