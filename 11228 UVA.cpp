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

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

int parent[1001],r[1001];

void reset(int n)
{
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
        r[i] = 1;
    }
}

int Find(int a)
{
    return (a==parent[a]) ? a : parent[a] = Find(parent[a]);
}

bool makePair(int u,int v)
{
    int a = Find(u);
    int b = Find(v);

    if(a==b)    return false;

    if(r[a]>=r[b])
    {
        parent[b] = a;
        r[a] += r[b];
    }

    else
    {
        parent[a] = b;
        r[b] += r[a];
    }
    return true;
}

class coord
{
public:
    int x,y;
    double d;
    coord(int a, int b,double dist)
    {
        x = a;
        y = b;
        d = dist;
    }
    bool operator < (const coord &p) const
    {
        return d < p.d;
    }
};

double _distance(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

vector<coord>c;

void Kruskal(int n,int r)
{
    double rail = 0,section = 1, road = 0,e = 0;

    for(int i=0;i<c.size();i++)
    {
        int a = c[i].x;
        int b = c[i].y;
        if(makePair(a,b))
        {
            double dist = c[i].d;
            if(dist>r)
            {
                section++;
                rail += dist;
            }
            else
                road+=dist;
            if(++e==n)    break;
        }
    }
    printf("%.lf %.lf %.lf\n",section,road,rail);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int test,n,r;

    scanf("%d",&test);

    for(int kase = 1;kase<=test;kase++)
    {
        c.clear();

        vector<pii>C;

        scanf("%d%d",&n,&r);
        reset(n);

        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            C.push_back(pii(x,y));
        }

        n = C.size();

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1 = C[i].first;
                int x2 = C[j].first;
                int y1 = C[i].second;
                int y2 = C[j].second;
                c.push_back(coord(i,j,_distance(x1,y1,x2,y2)));
            }
        }
        C.clear();
        sort(all(c));
        printf("Case #%d: ",kase);
        Kruskal(n-1,r);
    }
    return 0;
}
