#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define sif(n) scanf("%d",&n)
#define lif(n) scanf("%lld",&n)
#define MAX 1000005
#define MOD 100000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define p_b push_back
#define ff first
#define ss second
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >

typedef long long ll;
typedef unsigned long long ull;

enum COLOR { W = 0, G = 1, B = 2};

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
ll ara[200005];
ll tree[200000*3];

void build(int n,int b,int e)
{
    if(b==e)
    {
        tree[n] = ara[b];
        return;
    }
    int mid = (b+e)/2;
    int left = 2*n;
    int right = left+1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[n] = tree[left] + tree[right];
}

void update(int n,int b,int e,ll i,ll v)
{
    if(i<b||e<i)    return;
    if(b>=i&&e<=i)
    {
        tree[n] = v;
        return;
    }
    int left = 2*n;
    int right = left+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,v);
    update(right,mid+1,e,i,v);
    tree[n] = tree[right] + tree[left];
}

ll query(int n,int b,int e,ll i,ll j)
{
    if(j<b||e<i)    return 0;
    if(b>=i&&e<=j)  return tree[n];
    int left = 2*n;
    int right = left+1;
    int mid = (b+e)/2;
    ll L = query(left,b,mid,i,j);
    ll R = query(right,mid+1,e,i,j);
    return L+R;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,kase = 1;
    while(scanf("%d",&n)&&n)
    {
        if(kase>1)  puts("");
        for(int i=1;i<=n;i++)
            scanf("%d",&ara[i]);
        build(1,1,n);
        char choice[10];
        ll i,j,v;
        printf("Case %d:\n",kase++);
        while(scanf("%s",choice))
        {
            if(choice[0]=='M')
            {
                scanf("%lld%lld",&i,&j);
                printf("%lld\n",query(1,1,n,i,j));
            }
            else if(choice[0]=='S')
            {
                scanf("%lld%lld",&i,&v);
                update(1,1,n,i,v);
            }
            else    break;
        }
    }
    return 0;
}
