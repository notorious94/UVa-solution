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

map<string,int>visit,level;
char _forward(char c)
{
    if(c=='9')  return '0';
    return      ++c;
}

char _backward(char c)
{
    if(c=='0')  return '9';
    return      --c;
}

void bfs(string s,string f)
{
    /*
    if(visit[s]==-1||visit[f]==-1)
    {
        cout<<-1<<endl;
        return;
    }
    */
    if(s==f)
    {
        cout<<"0"<<endl;
        return;
    }
    queue<string>q;
    q.push(s);
    while(q.size())
    {
        string u = q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            string v = u;
            v[i] = _forward(v[i]);
            if(visit[v]==0)
            {
                visit[v] = 1;
                level[v] = 1 + level[u];
                q.push(v);
            }
            v = u;
            v[i] = _backward(v[i]);
            if(visit[v]==0)
            {
                visit[v] = 1;
                level[v] = 1 + level[u];
                q.push(v);
            }
        }
        if(visit[f]==1) break;
    }
    if(visit[f]==1) cout<<level[f]<<endl;
    else            cout<<-1<<endl;
}

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int t,m;
    cin>>t;
    string a,b,c,d;
    while(t--)
    {
        visit.clear();
        level.clear();
        string s,f;
        cin>>a>>b>>c>>d;
        s = a+b+c+d;
        cin>>a>>b>>c>>d;
        f = a+b+c+d;
        cin>>m;
        while(m--)
        {
            cin>>a>>b>>c>>d;
            visit[a+b+c+d] = -1;
        }
        bfs(s,f);
    }
    return 0;
}
