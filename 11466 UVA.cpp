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

typedef long long ll;
typedef unsigned long long ull;


ll p_factor(ll n)
{
    ll root=sqrt(n);

    vector<ll>prime_factor;

    for(ll i=2;i<=root;i++)
    {
        if(i>n)
            break;
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            prime_factor.push_back(i);
        }
    }
    if(n>1)
        prime_factor.push_back(n);

    if(prime_factor.size()==1)
        return -1;

    else
    {
        sort(prime_factor.begin(),prime_factor.end());
        return prime_factor[prime_factor.size()-1];
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,answer;

    while(1)
    {
        sf("%lld",&n);

        if(n==0)
            break;
        if(n==1||n==-1)
        {
            pf("-1\n");
            continue;
        }
        if(n<0)
            n*=-1;

        pf("%lld\n",p_factor(n));

    }
    return 0;
}
