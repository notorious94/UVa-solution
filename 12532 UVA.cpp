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

int ara[100005];
int tree[4*100005];

void build(int n,int b,int e)
{
    if(b==e)
    {
        tree[n] = ara[b];
        return;
    }
    int l = 2*n;
    int r = l+1;
    int m = (b+e)/2;
    build(l,b,m);
    build(r,m+1,e);
    tree[n] = tree[l] * tree[r];
}

void update(int n,int b,int e,int i,int v)
{
    if(b>i||e<i)    return;
    if(b>=i&&e<=i)
    {
        tree[n] = v;
        return;
    }
    int l = 2*n;
    int r = l+1;
    int m = (b+e)/2;
    update(l,b,m,i,v);
    update(r,m+1,e,i,v);
    tree[n] = tree[l] * tree[r];
}

int query(int n,int b,int e,int i,int j)
{
    if(b>j||e<i)    return 1;
    if(b>=i&&e<=j)
        return tree[n];
    int l = 2*n;
    int r = l+1;
    int m = (b+e)/2;
    int L = query(l,b,m,i,j);
    int R = query(r,m+1,e,i,j);
    return L*R;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,q;
    while(scanf("%d%d",&n,&q)==2)
    {
        for(int i=1;i<=n;i++)
        {
            sif(ara[i]);
            if(ara[i]==0)
                ara[i] = 0;
            else if(ara[i]>0)
                ara[i] = 1;
            else
                ara[i] = -1;
        }

        build(1,1,n);
        char c[10];
        int i,j,v;
        while(q--)
        {
            scanf("%s",c);
            if(c[0]=='P')
            {
                scanf("%d%d",&i,&j);
                int res = query(1,1,n,i,j);
                if(res==0)
                    printf("0");
                else if(res>0)
                    printf("+");
                else
                    printf("-");
            }
            else
            {
                scanf("%d%d",&i,&v);
                if(v<0)
                    v = -1;
                else if(v==0)
                    v = 0;
                else v = 1;
                update(1,1,n,i,v);
            }
        }
        puts("");
    }
    return 0;
}
