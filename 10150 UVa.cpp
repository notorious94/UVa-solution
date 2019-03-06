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
string node_name[25200];
vector<int>adj[25200];
vector<string>node_group2[17];
unordered_map<string,int>id;

char w[20];

bool isDoublets(string a,string b)
{
    int misMatch = 0;
    for(int i=0;a[i];i++)
        if(a[i]!=b[i]&&++misMatch>1)
            return false;
    return true;
}

void build(int g)
{
    int total = node_group2[g].size();
    for(int i=0;i<total;i++)
    {
        for(int j=i+1;j<total;j++)
        {
            if(isDoublets(node_group2[g][i],node_group2[g][j]))
            {
                int u = id[node_group2[g][i]];
                int v = id[node_group2[g][j]];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
}

bool visit[25200];
int parent[25200];

bool BFS(int s,int d)
{
    mem(visit,false);
    queue<int>q;
    q.push(s);
    parent[s] = -1;
    visit[s] = true;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(visit[v]==false)
            {
                visit[v]=true;
                q.push(v);
                parent[v] = u;
            }
            if(visit[d]==true)  return true;
        }
    }
    return false;
}

void pathPrint(int s)
{
    if(s==-1)   return;
    pathPrint(parent[s]);
    puts(node_name[s].c_str());
}

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n=0;
    while(gets(w))
    {
        if(!w[0])   break;
        id[w] = n++;
        int len = strlen(w);
        node_name[n-1] = w;
        node_group2[len].push_back(w);
    }

    for(int group=1;group<=16;group++)
        if(node_group2[group].size())
            build(group);

    int kase = 0;
    char u[20],v[20];
    while(scanf("%s%s",u,v)==2)
    {
        if(++kase>1)    puts("");
        if(strlen(u)!=strlen(v))
        {
            puts("No solution.");
            continue;
        }
        int a = id[u];
        int b = id[v];

        if(BFS(a,b))
            pathPrint(b);
        else
            puts("No solution.");
    }
    return 0;
}
