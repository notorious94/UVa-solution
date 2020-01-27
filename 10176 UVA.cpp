#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

/*
#pragma warning(disable:4786)
#pragma warning(disable:4996)
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// less for set and  less_equal  for multiset
// order_of_key (k) : Number of items strictly smaller than k
// find_by_order(k) : K-th element in a set (counting from zero) returns iterator
*/

/// M A C R O Starts Here
#define MOD 100000007
#define MOD2 998244353
#define INF INT_MAX
#define LINF LLONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define edge_pair pair<ll,pll>
#define D(x)            cerr << __LINE__ << ": " #x " = " << (x) << '\n'
#define DD(x, y)        cerr << __LINE__ << ": " #x " = " << (x) << ", " #y " = " << (y) << '\n'
#define DDD(x, y, z)    cerr << __LINE__ << ": " #x " = " << (x) << ", " #y " = " << (y) << ",  " #z " = " << (z) << '\n'
#define uniq(v) v.resize(unique(all(v)) - v.begin())
#define howMany(v,L,R) (upper_bound(all(v),R)-lower_bound(all(v),L))
#define pbds tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define bs_find(array,value) binary_search(all(array),value)
#define forn(i,x,n)   for(int i = x ; i <= n ; i++ )
#define ford(i,x,n)   for(int i = x ; i >= n ; i-- )
#define pb(x)           push_back(x)
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};
int kx[]= {2,2,-2,-2,1,-1,1,-1};
int ky[]= {1,-1,1,-1,2,2,-2,-2};

/// Template Starts here

template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}
/// Template Ends here

/// Functions Starts here

/// Bit-masking
/*
ll setBit(ll N,ll pos) {return N = N(1<<pos)};
ll reset(ll N,ll pos){return N = N & ~(1<<pos);}
bool check(ll N,ll pos){return (bool)(N & ((ll)1<<pos));}
*/

int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
ll toLlint(string s) { long long int sm; stringstream ss(s); ss>>sm; return sm;}

bool inBound(int x,int y,int r,int c)
{
    return (x>=0&&x<r&&y>=0&&y<c);
}

ll mulMod(ll a,ll b,ll M)
{
    return ((((a%M)*(b%M))%M)+M)%M;
}

ll bigMod(ll n,ll p,ll M)
{
    if(!p)  return 1%M;
    if(p&1)
        return (bigMod(n,p-1,M)%M*(n%M))%M;
    else
    {
        ll r =bigMod(n,p/2,M)%M;
        return (((r*r)%M)+M)%M;
    }
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

/// Functions Ends here
#define int ll

int dp[10005];

int solve(string n)
{
    int r = 0;
    for(int i=0;n[i];i++)
        r = (r+((n[i]-48)*dp[n.size()-i-1]))%131071;
    return r;
}

signed main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cout<<setprecision(10)<<fixed;
    string s;
    char c;
    dp[0] = 1;
    for(int i=1;i<=1e4;i++) dp[i] = (dp[i-1]*2)%131071;
    while(cin>>c)
    {
        if(c=='#')
        {
            (!solve(s)) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
            s.clear();
        }
        else if(c=='0'||c=='1') s+=c;
    }
    return 0;
}
