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

ll dphi[2000001];
int phi[2000001];
vector<bool>prime(20000001,true);
vector<int>primes;
void sieve()
{
    int limit = sqrt(2000000)+10;
    for(int i=4;i<prime.size();i+=2)
        prime[i]=false;
    limit = sqrt(prime.size());
    for(int i=3;i<=limit;i+=2)
        if(prime[i])
            for(int j=i*i;j<prime.size();j+=i*2)
                prime[j]=false;
    for(int i=2;i<=sqrt(prime.size());i++)
        if(prime[i])    primes.push_back(i);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    for(int i=2;i<=2000000;i++)
    {
        int temp = i, r = sqrt(i);
        phi[i] = i;

        for(int j=0;primes[j]<=r;j++)
        {
            if(temp%primes[j]==0)
            {
                while(temp%primes[j]==0)
                    temp/=primes[j];
                phi[i] -= phi[i]/primes[j];
            }
            if(prime[temp])     break;
        }
        if(temp>1)  phi[i]-=phi[i]/temp;
    }
    for(int i=2;i<=2000000;i++)
    {
        int n = i;
        while(n!=1)
        {
            if(dphi[n])
            {
                dphi[i]+=dphi[n];
                break;
            }
            else    dphi[i]++;
            n = phi[n];
        }
    }
    for(int i=2;i<=2000000;i++)
        dphi[i]+=dphi[i-1];
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("%lld\n",dphi[m]-dphi[n-1]);
    }

    return 0;
}
