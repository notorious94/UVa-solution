#include<bits/stdc++.h>
#include<tgmath.h>
#include<math.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi 3.141592653589793
#define R 6378
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int grid[101][101];
map<string,int>ID;
vector<pdd>loc;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return  0;
    if(r<0)     return -1;
    return 1;
}

/// M A C R O Ends Here

void reset(int n)
{
    loc.clear();
    loc.push_back(pdd(-1.0,-1.0));
    ID.clear();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            grid[i][j] = (i==j) ? 0 : INF;
}

double degtoRad(double deg)
{
    return deg * (pi/180.0);
}

double getDistance(double lat1,double lon1,double lat2,double lon2)
{
    double r = R;
    double dLat = degtoRad(lat2-lat1);
    double dLon = degtoRad(lon2-lon1);
    double a = sin(dLat/2.0)*sin(dLat/2.0) + cos(degtoRad(lat1))*cos(degtoRad(lat2))*sin(dLon/2.0)*sin(dLon/2.0);
    double c = 2.0*atan2(sqrt(a),sqrt(1.0-a));
    double d = r*c;
    return d;
}

void input(int n,int m)
{
    char c[50],a[50],b[50];
    double lat, lon;
    for(int i=1;i<=n;i++)
    {
        scanf("%s%lf%lf",c,&lat,&lon);
        ID[c] = i;
        loc.push_back(pdd(lat,lon));
    }
    while(m--)
    {
        scanf("%s%s",a,b);
        int x = ID[a];
        int y = ID[b];
        double dist = getDistance(loc[x].first,loc[x].second,loc[y].first,loc[y].second);
        if(grid[x][y]>dist)     grid[x][y] = int(dist+.5);
    }
}

void floydWarshall(int n)
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <=n; ++j)
                if(grid[i][k]!=INF && grid[k][j]!=INF)
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
}

void query(int q)
{
    char a[25],b[25];
    while(q--)
    {
        scanf("%s%s",&a,&b);
        int x = ID[a];
        int y = ID[b];
        (grid[x][y]>=INF) ? pf("no route exists\n") : pf("%d km\n",grid[x][y]);
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q;
    int kase = 0;

    while(sf("%d%d%d",&n,&m,&q))
    {
        if(!n && !m && !q)  break;
        if(++kase>1)  puts("");
        pf("Case #%d\n",kase);
        reset(n);
        input(n,m);
        floydWarshall(n);
        query(q);
    }

    return 0;
}
