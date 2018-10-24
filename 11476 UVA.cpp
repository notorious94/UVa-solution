#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

map<ll,int>freq;
vector<ll>F;
map<ll,int>::const_iterator it;
int lp[50001];
vector<int>prime;
ll limit = 2500000000;

void sieve(int limit = 50001)
{
    lp[0] = lp[1] = -1;
    for(int i=2;i<limit;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&i*prime[j]<limit;j++)
            lp[i*prime[j]]=i;
    }
}

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b&1) x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll power(ll a, ll b, ll c)
{
    ll x = 1, y = a;
    while(b>0)
    {
        if(b&1) x = mulmod(x,y,c);
        y = mulmod(y,y,c);
        b >>= 1;
    }
    return x;
}

bool witness(ll a,ll n)
{
    ll t = 0, u = n-1;
    while(u%2==0)
    {
        u>>=1;
        t++;
    }
    ll x[t+1];
    x[0] = power(a,u,n);
    for(int i=1; i<=t; i++)
    {
        x[i] = mulmod(x[i-1],x[i-1],n);
        if(x[i]==1 && x[i-1]!=1 && x[i-1]!=n-1)
            return true;
    }
    if(x[t]!=1)
        return true;
    return false;
}

bool isPrime(ll p)
{
    if(p<50001)
        return (lp[p]==p);
    srand(time(NULL));
    ll a = 2 + rand()%(p-4);
    if(witness(a,p))
        return false;
    return true;
}

ll PollardRho(long long n)
{
    ll x = 2, y = 2, i = 1, k = 2, d;
    while(true)
    {
        x = (mulmod(x, x, n) + n-1);
        if (x >= n)	x -= n;
        d = __gcd(abs(x-y),n);
        if (d > 1) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}

void factorize(ll n)
{
    ll r = sqrt(n);
    for(int i=0;i<prime.size()&&prime[i]<=r;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                F.push_back(prime[i]);
                n/=prime[i];
            }
            if(isPrime(n))  break;
        }
    }
    if(n>1)
        F.push_back(n);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ll n;
    int test;
    sieve();
    cin>>test;
    while(test--)
    {
        scanf("%lld",&n);
        printf("%lld =",n);
        while(true)
        {
            if(n==1)    break;
            else if(isPrime(n))
            {
                F.push_back(n);
                break;
            }
            ll div = PollardRho(n);
            if(isPrime(div))
            {
                while(n%div==0)
                {
                    F.push_back(div);
                    n/=div;
                }
                if(isPrime(n))
                {
                    F.push_back(n);
                    break;
                }
                else if(n<=limit)
                {
                    factorize(n);
                    break;
                }
            }
            else
            {
                n/=div;
                factorize(div);
                if(n<=limit)
                {
                    factorize(n);
                    break;
                }
            }
        }
        freq.clear();

        for(int i=0;i<F.size();i++)
            freq[F[i]]++;
        F.clear();
        for(it = freq.begin();it!=freq.end();it++)
        {
            ll k = it->first, p = it->second;
            if(it!=freq.begin())
                printf(" *");
            printf(" %lld",k);
            if(p>1)
                printf("^%lld",p);
        }
        puts("");
    }
    return 0;
}
