#include<bits/stdc++.h>
#include<unordered_map>
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

ll N,M;

bool SortFunc(ll i, ll j)
{
    if (i % M != j % M)
        return i % M < j % M;
    if (i & 1) // i is odd
    {
        if (j & 1)
            return i > j;
        return true;
    }
    if (j & 1)
    {
        return false;
    }
    return i < j;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    vector<ll>v;
    while(scanf("%lld%lld",&N,&M))
    {
        if(N==0&&M==0)
        {
            printf("0 0\n");
            break;
        }
        ll a;
        v.clear();
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&a);
            v.push_back(a);
        }
        sort(all(v),SortFunc);
        printf("%lld %lld\n",N,M);
        for(int i=0;i<v.size();i++)
            printf("%lld\n",v[i]);
    }
    return 0;
}
