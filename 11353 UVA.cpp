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
class number{
public:
    int n,f;
    number(int a,int b)
    {
        n = a;
        f = b;
    }
    bool operator < (const number &p)
    {
        if(f!=p.f)  return f < p.f;
        return n < p.n;
    }
};

vector<bool>prime(2000001,true);
vector<int>primes;
vector<number>ara;

void sieve()
{
    for(int i=4;i<2000001;i+=2)
        prime[i]=false;
    int r = sqrt(prime.size());
    for (int i=3;i<=r;i+=2)
        if(prime[i])
            for(int j=i*i;j<2000001;j+=i*2)
                prime[j]=false;
    for(int i=2;i<=r;i++)
        if(prime[i])
            primes.push_back(i);
}

int phi(int n)
{
    int p = 0,root = sqrt(n);
    for(int i=0;primes[i]<=root;i++)
    {
        if(n%primes[i]==0)
            while(n%primes[i]==0)
            {
                p++;
                n/=primes[i];
            }
        if(prime[n])    break;
    }
    if(n>1) p++;
    return p;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    for(int i=1;i<=2000000;i++)
        ara.push_back(number(i,phi(i)));
    sort(all(ara));
    int n,k=0;

    while(scanf("%d",&n)&&n)
        printf("Case %d: %d\n",++k,ara[n-1].n);

    return 0;
}
