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
#define ff first
#define ss second
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >

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

vector<int>adj[1000005];
bool visit[1000005],recStack[1000005];
stack<int>stick;
void topsort(int s)
{
    visit[s] = true;
    for(int i=0;i<adj[s].size();i++)
    {
        int v = adj[s][i];
        if(visit[v]==false)
            topsort(v);
    }
    stick.push(s);
}

bool isCycle(int s)
{
    if(visit[s] == false)
    {
        visit[s] = true;
        recStack[s] = true;

        for(int i=0;i<adj[s].size();i++)
        {
            int v = adj[s][i];
            if (!visit[v]&&isCycle(v))
                return true;
            else if (recStack[v])
                return true;
        }
    }
    recStack[s] = false;  // remove the vertex from recursion stack
    return false;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,u,v;

    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        for(int i=1;i<=n;i++)
        {
            visit[i] = false;
            recStack[i] = false;
            adj[i].clear();
        }

        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].p_b(v);
        }

        bool cycle_flag = false;


        for(int i=1;i<=n;i++)
        {
            if(visit[i]==false)
            {
                cycle_flag = isCycle(i);
                if(cycle_flag==true)
                {
                    break;
                }
            }
        }

        if(cycle_flag)
            puts("IMPOSSIBLE");

        else
        {
            mem(visit,false);

            while(stick.size())
                stick.pop();

            for(int i=1;i<=n;i++)
                if(visit[i]==false)
                    topsort(i);

            while(stick.size())
            {
                printf("%d\n",stick.top());
                stick.pop();
            }
        }
    }

    return 0;
}
