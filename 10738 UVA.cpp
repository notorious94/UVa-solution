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
int lp[1000001];
vector<int>prime;
int mn[1000001];
int M[1000001];

void sieve()
{
    for(int i=2;i<1000001;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=lp[i]&&i*prime[j]<=1000000;j++)
            lp[prime[j]*i]=prime[j];
    }
    for(int i=0;i<prime.size();i++)
        lp[prime[i]] = -1;
}

void primef(int n)
{
    int r = sqrt(n),tmp = n;
    bool square = true;
    int f = 0;
    for(int i=0;prime[i]<=r;i++)
    {
        if(n%prime[i]==0)
        {
            int F = 0;
            while(n%prime[i]==0)
            {
                f++;
                F++;
                n/=prime[i];
            }
            if(F>1) square = false;
            r = sqrt(n);
        }
        if(lp[n]==-1)
            break;
    }
    if(n>1)     f++;

    if(f==1)
        mn[tmp] = -1;
    else if(!square)
        mn[tmp] = 0;
    else if(f%2==0)
        mn[tmp] = 1;
    else
        mn[tmp] = -1;
    M[tmp] +=(M[tmp-1]+mn[tmp]);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    mn[1] = 1;
    M[1] = 1;
    for(int i=2;i<=1000000;i++)
        primef(i);
    int n;
    while(scanf("%d",&n)&&n)
        printf("%8d%8d%8d\n",n,mn[n],M[n]);
    return 0;
}
