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

int indegree[101];
vector<int>Adj[101];

void clean(int n)
{
    for(int i=1;i<=n;i++)
    {
        indegree[i]=0;
        Adj[i].clear();
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,kase = 1;
    char soda[100],cola[100];
    while(scanf("%d",&n)==1)
    {
        clean(n);
        map<int,string>s;
        map<string,int>id;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",soda);
            id[soda] = i;
            s[i] = soda;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s%s",soda,cola);
            int a = id[soda];
            int b = id[cola];
            Adj[a].p_b(b);
            indegree[b]++;
        }

        priority_queue<int, vector<int>, greater<int> > pq;

        for(int i=1;i<=n;i++)
            if(!indegree[i])
                pq.push(i);

        vector<int>result;

        while(pq.size())
        {
            int u = pq.top();
            result.p_b(u);
            pq.pop();
            for(int i=0;i<Adj[u].size();i++)
            {
                int v = Adj[u][i];
                if(--indegree[v]==0)
                    pq.push(v);
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:",kase++);
        for(int i=0;i<result.size();i++)
            printf(" %s",s[result[i]].c_str());
        puts(".\n");
    }
    return 0;
}
