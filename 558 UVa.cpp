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
#define all(name) name.begin(),name.end()

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

vector<int>graph[1000];
vector<int>cost[1000];
int dist[1000];

void init(int n)
{
    for(int i=0;i<n;i++)
    {
        dist[i] = INF;
        cost[i].clear();
        graph[i].clear();
    }
}

void input(int m)
{
    int a,b,c;
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back(b);
        cost[a].push_back(c);
    }
}

bool BellmanFord(int n)
{
    dist[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        bool update = false;
        for (int j = 0; j < n ; ++j)
        {
            for(int k = 0; k < graph[j].size(); ++k)
            {
                if(dist[j]!=INF)
                {
                    if(dist[j]+cost[j][k]<dist[graph[j][k]])
                    {
                        update = true;
                        dist[graph[j][k]] = dist[j]+cost[j][k];
                    }
                }
            }
        }
        if(i==n && update)
            return true;
        if(update == false)
            return false;
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,m;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        init(n);
        input(m);
        if(BellmanFord(n))
            printf("possible\n");
        else
            printf("not possible\n");
    }

    return 0;
}
