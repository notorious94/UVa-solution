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

int limit = sqrt(1000000000)+10;
vector<bool>prime(limit,true);
vector<int>primes;

void sieve()
{
    for(int i=4;i<limit;i+=2)
        prime[i]=false;

    int r = sqrt(limit);

    for(int i=3;i<=r;i+=2)
        if(prime[i])
            for(int j=i*i;j<limit;j+=i*2)
                prime[j]=false;

    for(int i=2;i<limit;i++)
        if(prime[i])
            primes.push_back(i);
    prime.clear();
}

ll phi(ll n)
{
    if(n==1)    return 0;
    int r = sqrt(n);
    ll result = n;
    for(int i=0;primes[i]<=r;i++)
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
                n /= primes[i];
            result -= result/primes[i];
        }
    if(n>1) result-=result/n;
    return result;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    ll n;

    while(scanf("%lld",&n)&&n)
        printf("%lld\n",phi(n));

    return 0;
}
