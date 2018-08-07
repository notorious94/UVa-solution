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

int lp[10000001];
vector<int>primes;

void sieve()
{
    lp[0] = lp[1] = -1;
    for(int i=2;i<10000001;i++)
    {
        if(lp[i]==0)
        {
            lp[i] = i;
            primes.push_back(i);
        }
        for(int j=0;j<primes.size() && i*primes[j]<10000001 && primes[j]<=i;j++)
            lp[i*primes[j]] = i;
    }
}

void generate_sum(int n,int a,int b)
{
    int half = n/2;
    for(int i=0;i<primes.size()&&primes[i]<=half;i++)
    {
        int segment = n - primes[i];
        if(lp[segment]==segment)
        {
            printf("%d %d %d %d\n",a,b,primes[i],segment);
            return;
        }
    }
    puts("Impossible.");
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n&1)     generate_sum(n-5,2,3);
        else        generate_sum(n-4,2,2);
    }
    return 0;
}
