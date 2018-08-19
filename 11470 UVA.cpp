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

/*
int lp[32001];
vector<int>prime;

void sieve(int limit = 32001)
{
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
*/

ll square[10][10];
int n;

ll get_sum(int i,int j,int limit)
{
    ll sum = 0;
    int x = i,y = j;
    int lx,ly;
    for(int l=0;l<limit;l++,y++)
    {
        sum+=square[x][y];
        lx = x,ly = y;
    }
    sum-=square[lx][ly];
    y--;
    for(int l=0;l<limit;l++,x++)
    {
        sum+=square[x][y];
        lx = x,ly = y;
    }
    sum-=square[lx][ly];
    x--;
    for(int l=0;l<limit;l++,y--)
    {
        sum+=square[x][y];
        lx = x,ly = y;
    }
    sum-=square[lx][ly];
    y++;
    for(int l=0;l<limit;l++,x--)
        sum+=square[x][y];
    x++;
    if(limit>1)
        sum-=square[i][j];
    return sum;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int kase = 1;
    while(scanf("%d",&n)&&n)
    {
        int limit = (n%2==0) ? (n/2) : (n/2)+1;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%lld",&square[i][j]);

        vector<ll>result;

        for(int i=0,j=0,k=0;k<limit;n-=2,k++,j++,i++)
            result.push_back(get_sum(i,j,n));

        printf("Case %d: %lld",kase++,result[0]);

        for(int i=1;i<result.size();i++)
            printf(" %lld",result[i]);

        puts("");
    }
    return 0;
}

