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
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

vector<int>adj[2500];
int day[2500];
bool visit[2500];

void BFS(int s)
{
    mem(visit,false);
    map<int, int>freq;
    map<int, int>:: iterator it;
    queue<int>q;
    q.push(s);
    day[s] = 0;
    visit[s]=true;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(visit[v]==false)
            {
                visit[v] = true;
                day[v] = day[u]+1;
                freq[day[v]]++;
                q.push(v);
            }
        }
    }
    int ans = 0;
    int boom = 0;
    for(it = freq.begin();it!=freq.end();it++)
    {
        int day = it->first;
        int f = it->second;
        if(f>boom)
        {
            boom = f;
            ans = day;
        }
    }
    (!ans) ? pf("0\n") : pf("%d %d\n",boom,ans);
}

void init(int e)
{
    int c,v;
    for(int i=0;i<e;i++)
    {
        adj[i].clear();
        scanf("%d",&c);
        while(c--)
        {
            scanf("%d",&v);
            adj[i].push_back(v);
        }
    }
}

void query(int n)
{
    int s;
    while(n--)
    {
        scanf("%d",&s);
        BFS(s);
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int e, n;
    while(scanf("%d",&e)==1)
    {
        init(e);
        scanf("%d",&n);
        query(n);
    }
    return 0;
}
