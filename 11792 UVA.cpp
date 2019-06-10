#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
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
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define rep(i,n)  for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

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

bool isPal(string s)
{
    int half = s.size()/2;
    for(int i=0,j=s.size()-1;i<half;i++,j--)
        if(s[i]!=s[j])  return false;
    return true;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

bool inBound(int x,int y,int r,int c)
{
    return (x>=0&&x<r&&y>=0&&y<c);
}

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b&1) x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
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

vector<int>g[10005];
bool visit[10005];
int level[10005];
int freq[10005];
double timer[10005];

int bfs(int s,int t)
{
    if(s==t)    return 0;
    mem(visit,false);
    level[s] = 0;
    visit[s] = true;
    queue<int>q;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(auto v : g[u])
        {
            if(!visit[v])
            {
                visit[v] = true;
                level[v] = 2 + level[u];
                q.push(v);
                if(v==t)    return level[t];
            }
        }
    }
}

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int test,n,s;
    cin>>test;
    int k = 0;
    while(test--)
    {
        cin>>n>>s;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            freq[i] = timer[i] = 0;
        }
        while(s--)
        {
            int u,v;
            cin>>u;
            freq[u]++;
            while(cin>>v&&v)
            {
                g[u].push_back(v);
                g[v].push_back(u);
                freq[v]++;
                u = v;
            }
        }
        vector<int>important;
        for(int i=1;i<=n;i++)
            if(freq[i]>1)
                important.push_back(i);

        for(int i=0;i<important.size();i++)
        {
            for(int j=i+1;j<important.size();j++)
            {
                int start  = important[i];
                int finish = important[j];
                int dist = bfs(start,finish);
                timer[start]+=dist;
                timer[finish]+=dist;
            }
        }
        int x = INF,min_sum = INF;
        for(int i=0;i<important.size();i++)
        {
            int station = important[i];
            int sum = timer[station];
            if(sum<min_sum)
            {
                min_sum = sum;
                x = station;
            }
            else if(min_sum==sum)
                x = min(x,station);
        }
        cout<<"Krochanska is in: "<<x<<endl;
    }
    return 0;
}
