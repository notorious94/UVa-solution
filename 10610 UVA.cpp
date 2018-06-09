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

vector<int>List[1005];
vector<pdd>coord;
bool visit[1005];
int level[1005];
char line[5000];

void reset()
{
    coord.clear();
    for(int i=0;i<1005;i++)
        List[i].clear(),visit[i]=false;
}

void input()
{
    double x,y;
    getc(stdin);
    while(gets(line))
    {
        if(!line[0])    break;
        sscanf(line,"%lf%lf",&x,&y);
        coord.push_back(pdd(x,y));
    }
}

void set_graph(double m)
{
    for(int i=0;i<coord.size()-1;i++)
    {
        for(int j=i+1;j<coord.size();j++)
        {
            double d = _distance(coord[i].first,coord[i].second,coord[j].first,coord[j].second);
            if(d<=m)
            {
                List[i].push_back(j);
                List[j].push_back(i);
            }
        }
    }
}

int BFS(int s,int d)
{
    visit[s] = true;
    level[s] = 0;
    queue<int>q;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<List[u].size();i++)
        {
            int v = List[u][i];
            if(visit[v]==false)
            {
                visit[v] = true;
                level[v] = level[u]+1;
                q.push(v);
            }
        }
        if(visit[d])    return level[d];
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double v,m;

    while(scanf("%lf%lf",&v,&m))
    {
        if(!v&&!m)  break;
        m=v*m*60.0;
        reset();
        input();
        set_graph(m);
        int ans = BFS(0,1);
        if(ans==-1) puts("No.");
        else        pf("Yes, visiting %d other holes.\n",ans-1);
    }
    return 0;
}
