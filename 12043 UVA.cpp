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

int lp[100001];
vector<int>prime;
int nod[100001],sod[100001];

void sieve()
{
    for(int i=2;i<=100000;i++)
    {
        if(lp[i]==0)
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=100000&&prime[j]<=lp[i];j++)
            lp[i*prime[j]] = prime[j];
    }
    for(int i=0;i<prime.size();i++)
        lp[prime[i]] = -1;
}

void prime_factorize(int n)
{
    int tmp = n;
    int divisor = 1,sum = 1;
    int root = sqrt(n);
    for(int i=0;prime[i]<=root;i++)
    {
        if(n%prime[i]==0)
        {
            int factor = 1;
            int curr_term = 1,curr_sum = 1;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                factor++;
                curr_term*=prime[i];
                curr_sum+=curr_term;
            }
            divisor*=factor;
            sum *= curr_sum;
        }
        if(lp[n]==-1)   break;
    }
    if(n>1)
    {
        divisor*=2;
        sum *=(1+n);
    }
    nod[tmp] = divisor;
    sod[tmp] = sum;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    for(int i=1;i<=100000;i++)
        prime_factorize(i);
    int t,a,b,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&k);
        ll SOD=0,NOD=0;
        for(int i=1;i*k<=b;i++)
        {
            if(i*k>=a)
            {
                SOD+=sod[i*k];
                NOD+=nod[i*k];
            }
        }
        printf("%lld %lld\n",NOD,SOD);
    }
    return 0;
}
