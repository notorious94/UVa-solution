#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 1000001
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

vector<bool>prime(MAX,true);
vector<int>p;

void sieve()
{
    int r = sqrt(prime.size());

    for(int i=4;i<MAX;i+=2)
        prime[i] = false;

    for(int i=3;i<=r;i+=2)
        if(prime[i])
            for(int j=i*i; j<MAX;j+=i*2)
                prime[j] = false;

    p.push_back(2);

    for(int i=3;i<MAX;i+=2)
        if(prime[i])    p.push_back(i);
}

int sumofDivisor(ll n)
{
    ll res = 1,tmp = n, r = sqrt(n);
    for (int i = 0; p[i] <= r; i++)
    {
        ll count = 0, curr_sum = 1, curr_term = 1;
        while (n % p[i] == 0)
        {
            count++;
            n = n / p[i];
            curr_term *= p[i];
            curr_sum += curr_term;
        }
        res *= curr_sum;
    }
    if (n >= 2)     res *= (1 + n);
    res-=tmp;

    if(res<tmp)           return 0;
    else if(res==tmp)     return 1;
    else                  return 2;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    string s[] = {"deficient","perfect","abundant"};
    ll t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        pf("%s\n",s[sumofDivisor(n)].c_str());
    }
    return 0;
}
