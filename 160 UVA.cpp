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

vector<bool>p(100,true);
vector<int>prime,result[101];
map<int,int>factors;
map<int,int>::iterator it;

void sieve()
{
    for(int i=4;i<100;i+=2)
        p[i] = false;
    for(int i=3;i<100;i+=2)
        if(p[i])
            for(int j=i*i;j<100;j+=2*i)
                p[j] = false;
    for(int i=2;i<100;i++)
        if(p[i])
            prime.push_back(i);
    p.clear();
}

void prime_factorization(int n)
{
    int r = sqrt(n);
    for(int i=0;i<25&&prime[i]<=r;i++)
        if(n%prime[i]==0)
        {
            int f = 0;
            while(n%prime[i]==0)
            {
                f++;
                n/=prime[i];
            }
            factors[prime[i]]+=f;
        }
    if(n>1) factors[n]++;
}
void DP()
{
    for(int i=2;i<=100;i++)
    {
        prime_factorization(i);
        for(it = factors.begin();it!=factors.end();it++)
            result[i].push_back(it->second);
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    DP();
    int n;
    while(scanf("%d",&n)&&n)
    {
        printf("%3d! =",n);

        for(int i=0;i<result[n].size();i++)
        {
            if(i==15)   printf("\n      ");
            printf("%3d",result[n][i]);
        }
        puts("");
    }
    return 0;
}
