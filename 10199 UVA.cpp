#include<bits/stdc++.h>
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

typedef long long ll;
typedef unsigned long long ull;

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};
int kx[]= {2,2,-2,-2,1,-1,1,-1};
int ky[]= {1,-1,1,-1,2,2,-2,-2};

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

map<string,int>id;
map<int,string>id2;
vector<string>ans;
vector<int>adj[105];
bool visit[105],ap[105];
int t = 0,cut_p = 0,parent[105],disc[105],low[105];

void reset(int n)
{
    cut_p = t = 0;
    id.clear();
    id2.clear();
    ans.clear();
    for(int i=1;i<=n;i++)
    {
        ap[i]=visit[i]=false;
        adj[i].clear();
        parent[i] = -1;
    }
}

void find_AP(int u)
{
    int child = 0;
    visit[u] = true;
    low[u] = disc[u] = ++t;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(visit[v]==false)
        {
            child++;
            parent[v]=u;
            find_AP(v);
            low[u] = min(low[u],low[v]);
            if(parent[u]==-1 && child>1)
                ap[u] = true;
            else if(parent[u]!=-1 && disc[u]<=low[v])
                ap[u] = true;
        }
        else if(v!=parent[u])
            low[u] = min(low[u],disc[v]);
    }
}

void call(int n)
{
    for(int i=1;i<=n;i++)
        if(visit[i]==false)
            find_AP(i);

    for(int i=1;i<=n;i++)
        if(ap[i])
            ans.push_back(id2[i]);

    sort(all(ans));

    cut_p = ans.size();
}

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,kase = 0;
    string city,u,v;

    while(cin>>n&&n)
    {
        if(++kase>1)    cout<<endl;
        reset(n);

        for(int i=1;i<=n;i++)
        {
            cin>>city;
            id[city] = i;
            id2[i] = city;
        }

        cin>>m;

        while(m--)
        {
            cin>>u>>v;
            int x = id[u] , y = id[v];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        call(n);

        cout<<"City map #"<<kase<<": "<<cut_p<<" camera(s) found"<<endl;

        for(int i=0;i<cut_p;i++)
            cout<<ans[i]<<endl;

    }

    return 0;
}
