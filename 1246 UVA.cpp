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

int lp[101];
vector<int> prime,ans;
vector<int> :: iterator it;

void sieve()
{
    for(int i=2;i<101;i++)
    {
        if(lp[i]==0)
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<101&&prime[j]<=i;j++)
            lp[i*prime[j]]=i;
    }
}


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,l,r;

    sieve();

    for(int i=0;i<=10000;i++)
    {
        int d = i,r = sqrt(i),cnt = 0;
        for(int j=1;j<=r;j++)
        if(i%j==0)  (i/j==j) ? cnt++ : cnt+=2;
        if(lp[cnt]==cnt)       ans.push_back(i);
    }

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        int i = lower_bound(all(ans),l) - ans.begin();
        bool print = false,f = true;
        for(;i<ans.size()&&ans[i]<=r;i++)
        {
            print = true;
            if(f)   printf("%d",ans[i]),f = false;
            else    printf(" %d",ans[i]);
        }
        if(!print)  printf("-1");
        puts("");
    }
    return 0;
}
