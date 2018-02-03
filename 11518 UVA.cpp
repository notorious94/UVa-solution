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

vector<int>adj[10001];
bool visit[10001];
void DFS_Call(int s);
int call;

void input(int n,int m,int l)
{
    int a,b;
    call = 0;
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        visit[i]=false;
    }

    while(m--)
    {
        sf("%d%d",&a,&b);
        adj[a].push_back(b);
    }

    while(l--)
    {
        scanf("%d",&a);
        if(!visit[a])   DFS_Call(a);
    }
    pif(call);
}

void DFS_Call(int s)
{
    call++;
    visit[s] = true;
    for(int i=0;i<adj[s].size();i++)
    {
        int v = adj[s][i];
        if(!visit[v])   DFS_Call(v);
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,l,test;
    scanf("%d",&test);

    while(test--)
    {
        sf("%d%d%d",&n,&m,&l);
        input(n,m,l);
    }

    return 0;
}
