#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 1000005
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

enum COLOR { W = 0, G = 1, B = 2};

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};

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

bool visit[27];
int indeg[27];
vector<int>adj[27],topsort,node;
bool cycle = false;

void reset()
{
    cycle = false;
    topsort.clear(),node.clear();
    for(int i=0; i<27; i++)
    {
        visit[i] = indeg[i] = false;
        adj[i].clear();
    }
}

void allTopSort()
{
    bool flag = false;
    for(int i=0; i<node.size(); i++)
    {
        int u = node[i];
        if(indeg[u]==0&&visit[u]==false)
        {
            visit[u] = true;
            topsort.push_back(u);
            for(int j=0; j<adj[u].size(); j++)
            {
                int v = adj[u][j];
                indeg[v]--;
            }
            allTopSort();
            visit[u] = false;
            topsort.pop_back();
            for(int j=0; j<adj[u].size(); j++)
            {
                int v = adj[u][j];
                indeg[v]++;
            }
            flag = true;
        }
    }

    if(!flag)
    {
        if(topsort.size()!=node.size())
            cycle = true;
        else
        {
            printf("%c",topsort[0]+'A');
            for(int i=1; i<topsort.size(); i++)
                printf(" %c",topsort[i]+'A');
            puts("");
        }
    }
}

void process(char n[],char e[])
{
    for(int i=0;n[i];i++)
        if(n[i]!=32)    node.push_back(n[i]-'A');

    vector<int>temp;

    for(int i=0;e[i];i++)
    {
        if(e[i]!=32 && e[i]!='<')
        {
            temp.push_back(e[i]-'A');
            if(temp.size()==2)
            {
                int u = temp[0];
                int v = temp[1];
                adj[u].push_back(v);
                indeg[v]++;
                temp.clear();
            }
        }
    }
    sort(all(node));
    for(int i=0;i<node.size();i++)
        sort(all(adj[node[i]]));
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    char n[1000],e[1000],blank[5];
    scanf("%d\n",&test);
    while(test--)
    {
        gets(n);
        gets(e);
        reset();
        process(n,e);
        allTopSort();
        if(cycle)   puts("NO");
        if(test)    puts(""),gets(blank);
    }
    return 0;
}
