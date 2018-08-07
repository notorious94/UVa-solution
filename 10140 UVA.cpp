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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

int lp[46341];
vector<int>prime,primes;

void sieve()
{
    lp[0] = lp[1] = -1;
    for(int i=2;i<46341;i++)
    {
        if(lp[i]==0)
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&i*prime[j]<46341;j++)
            lp[i*prime[j]] = i;
    }
}

bool isPrime(int n)
{
    if(n<46341)   return (lp[n]==n);
    int root = sqrt(n);
    for(int i=0;i<prime.size()&&prime[i]<=root;i++)
        if(n%prime[i]==0)   return false;
    return true;
}

void generate_prime(ll L,ll U)
{
    primes.clear();
    for(ll i=L;i<=U;i++)
        if(isPrime(i))
            primes.push_back(i);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    ll L,U;

    while(scanf("%lld%lld",&L,&U)==2)
    {
        generate_prime(L,U);

        int close = INF,far = -INF,a,b,A,B;
        bool update = false;

        for(int i=1;i<primes.size();i++)
        {
            if(close > primes[i]-primes[i-1])
            {
                close = primes[i] - primes[i-1];
                a = primes[i-1];
                b = primes[i];
                update = true;
            }
            if(far < primes[i]-primes[i-1])
            {
                far = primes[i] - primes[i-1];
                A = primes[i-1];
                B = primes[i];
                update = true;
            }
        }
        if(update)  printf("%d,%d are closest, %d,%d are most distant.\n",a,b,A,B);
        else        puts("There are no adjacent primes.");
    }
    return 0;
}
