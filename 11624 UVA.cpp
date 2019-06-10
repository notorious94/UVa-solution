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
    for(int i=0,j=s.size()-1; i<half; i++,j--)
        if(s[i]!=s[j])
            return false;
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
        if (b&1)
            x = (x + y) % c;
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

string grid[1005];
int fire[1005][1005];
int joe[1005][1005];
queue<pii>qf,qj;

void setFire(int r,int c)
{
    while(qf.size())
    {
        int ux = qf.front().first;
        int uy = qf.front().second;
        qf.pop();
        for(int i=0; i<4; i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if(inBound(vx,vy,r,c)&&grid[vx][vy]!='#'&&fire[vx][vy]==INF)
            {
                fire[vx][vy] = 1 + fire[ux][uy];
                qf.push({vx,vy});
            }
        }
    }
}

void moveJoe(int r,int c)
{
    while(qj.size())
    {
        int ux = qj.front().first;
        int uy = qj.front().second;
        qj.pop();
        for(int i=0; i<4; i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if(inBound(vx,vy,r,c)&&grid[vx][vy]!='#'&&joe[vx][vy]==INF)
            {
                joe[vx][vy] = 1 + joe[ux][uy];
                qj.push({vx,vy});
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

    int r,c,t;
    cin>>t;
    for(int kase = 1;kase<=t;kase++)
    {
        cin>>r>>c;
        for(int i=0; i<r; i++)
        {
            cin>>grid[i];
            for(int j=0; j<c; j++)
            {
                joe[i][j] = fire[i][j] = INF;
                if(grid[i][j]=='F')
                {
                    fire[i][j] = 0;
                    qf.push({i,j});
                }
                if(grid[i][j]=='J')
                {
                    joe[i][j] = 0;
                    qj.push({i,j});
                }
            }
        }

        setFire(r,c);
        moveJoe(r,c);

        int ans = INF;

        for(int i=0; i<r; i++)
        {
            if(joe[i][0]<fire[i][0])
                ans = min(ans,joe[i][0]);
            if(joe[i][c-1]<fire[i][c-1])
                ans = min(ans,joe[i][c-1]);
        }

        for(int i=0; i<c; i++)
        {
            if(joe[0][i]<fire[0][i])
                ans = min(ans,joe[0][i]);
            if(joe[r-1][i]<fire[r-1][i])
                ans = min(ans,joe[r-1][i]);
        }

        //cout<<"Case "<<kase<<": ";
        if(ans==INF)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<++ans<<endl;
    }
    return 0;
}
