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
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

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

vector<int> adj_list[100000];
bool visit[100000];
int level[100000];

void reset(int n)
{
    for(int i=0;i<n;i++)
        adj_list[i].clear(),visit[i]=false;
}

void input()
{
    int n;
    scanf("%d",&n);
    reset(n);
    while(n--)
    {
        int u,v,c;
        scanf("%d%d",&u,&c);
        while(c--)
        {
            scanf("%d",&v);
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
    }
}

int BFS()
{
    int s,d;
    scanf("%d%d",&s,&d);
    printf("%d %d ",s,d);
    visit[s] = true;
    level[s] = 0;
    queue<int>q;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<adj_list[u].size();i++)
        {
            int v = adj_list[u][i];
            if(visit[v]==false)
            {
                visit[v]=true;
                level[v] = level[u]+1;
                q.push(v);
            }
        }
        if(visit[d])    return level[d]-1;
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    scanf("%d",&test);
    while(test--)
    {
        input();
        printf("%d\n",BFS());
        if(test)    puts("");
    }
    return 0;
}
