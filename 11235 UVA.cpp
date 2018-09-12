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

int freq1[200005];
int freq2[100005];
int ara[100005];
int Start[100005];
int End[100005];
int tree[400005];

void build(int n,int b,int e)
{
    if(b==e)
    {
        tree[n] = freq2[b];
        return;
    }
    int left = n*2;
    int right = left+1;
    int mid = (b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[n] = max(tree[left],tree[right]);
}

int query(int n,int b,int e,int i,int j)
{
    if(b>j || e<i)  return 0;
    if(b>=i && e<=j)
        return tree[n];

    int left = n*2;
    int right = left+1;
    int mid = (b+e)/2;
    int p = query(left,b,mid,i,j);
    int q = query(right,mid+1,e,i,j);
    return max(p,q);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n,q;
    while(sif(n)&&n)
    {
        sif(q);
        mem(freq1,0);
        int id = 1;
        for(int i=1;i<=n;i++)
        {
            sif(ara[i]);
            freq1[ara[i]+100000]++;
            if(i==1)
            {
                Start[i] = id;
                continue;
            }
            if(ara[i]!=ara[i-1])    Start[i] = id = i;
            else                    Start[i] = id;
        }

        for(int i=1;i<=n;i++)
        {
            int f = freq1[ara[i]+100000];
            freq2[i] = f;
            End[i] = Start[i] + f - 1;
        }

        build(1,1,n);

        while(q--)
        {
            int l,r;
            sif(l);
            sif(r);
            if(ara[l]==ara[r])
                pif(r-l+1);
            else
            {
                int b = End[l]+1;
                int e = Start[r]-1;
                int cnt1 = End[l] - l + 1;
                int cnt2 = r - Start[r] + 1;
                int cnt3 = (b>e) ? 0 : query(1,1,n,b,e);
                pif(max(max(cnt1,cnt2),cnt3));
            }
        }
    }
    return 0;
}
