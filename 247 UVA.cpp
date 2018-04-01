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

map<int,string>ID;
map<string,int>id;
vector<int>G[26],T[26],top,scc;
bool visit[26];

void init(int n)
{
    ID.clear();
    id.clear();
    top.clear();
    scc.clear();
    for(int i=1;i<=n;i++)
        G[i].clear(),T[i].clear();
}

void edge(int m)
{
    char u[30],v[30];
    int a,b,i = 1;
    while(m--)
    {
        scanf("%s%s",u,v);
        a = id[u];
        b = id[v];
        if(!a)  id[u] = i++,a = i-1,ID[a] = u;
        if(!b)  id[v] = i++,b = i-1,ID[b] = v;
        G[a].push_back(b);
        T[b].push_back(a);
    }
}

void printResult()
{
    printf("%s",ID[scc[0]].c_str());
    for(int i=1;i<scc.size();i++)
        printf(", %s",ID[scc[i]].c_str());
    puts("");
}

void DFS_One(int s)
{
    visit[s] = true;
    for(int i=0;i<G[s].size();i++)
        if(!visit[G[s][i]])
            DFS_One(G[s][i]);
    top.push_back(s);
}

void call_One(int n)
{
    mem(visit,false);
    for(int i=1;i<=n;i++)
        if(!visit[i])
            DFS_One(i);
}

void DFS_Two(int s)
{
    visit[s] = true;
    for(int i=0;i<T[s].size();i++)
        if(!visit[T[s][i]])
            DFS_Two(T[s][i]);
    scc.push_back(s);
}

void call_Two()
{
    mem(visit,false);
    for(int i=top.size()-1;i>=0;i--)
        if(!visit[top[i]])
        {
            scc.clear();
            DFS_Two(top[i]);
            printResult();
            scc.clear();
        }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,kase=0;
    while(scanf("%d%d",&n,&m))
    {
        if(!n && !m)    break;
        if(++kase>1)    puts("");
        printf("Calling circles for data set %d:\n",kase);
        init(n);
        edge(m);
        call_One(n);
        call_Two();
    }
    return 0;
}
