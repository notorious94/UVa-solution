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
#define piii pair<pii,int>
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
int kx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int ky[] = {1, -1, 1, -1, 2, 2, -2, -2};

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

map< vector<int> ,int > combo;
map< vector<int> ,int > :: const_iterator it;
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int f;
    while(scanf("%d",&f) && f)
    {
        vector<int>c(5);
        int max_freq = 0;
        for(int i=0;i<f;i++)
        {
            scanf("%d%d%d%d%d",&c[0],&c[1],&c[2],&c[3],&c[4]);
            sort(all(c));
            max_freq = max(max_freq,++combo[c]);
        }
        int ans = 0;
        for(it = combo.begin();it!=combo.end();it++)
            if(it->second==max_freq)
                ans++;
        combo.clear();
        printf("%d\n",ans*max_freq);
    }
    return 0;
}
