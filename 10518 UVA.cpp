#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
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

ll n,MOD;

void multiply(int m1[3][3],int m2[3][3])
{
    int r[3][3];

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            r[i][j] = 0;
            for(int k=0;k<3;k++)
            {
                r[i][j] += m1[i][k]%MOD*m2[k][j]%MOD;
                r[i][j] %= MOD;
            }
        }

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m1[i][j] = r[i][j];
}

void power(ll p,int m[3][3])
{
    if(p<=1)    return;
    power(p/2,m);
    multiply(m,m);
    if(p&1)
    {
        int M[3][3]={{1,1,1},
                     {1,0,0},
                     {0,0,1}};
        multiply(m,M);
    }
}

int nth_term(ll n)
{
    if(n<=1)    return 1%MOD;
    int M[3][3]={{1,1,1},
                 {1,0,0},
                 {0,0,1}};
    power(n-1,M);
    return (M[0][0]+M[0][1]+M[0][2])%MOD;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int kase = 0;
    while(scanf("%lld%lld",&n,&MOD))
    {
        if(!n&&!MOD)    break;
        printf("Case %d: %lld %lld %d\n",++kase,n,MOD,nth_term(n));
    }
    return 0;
}
