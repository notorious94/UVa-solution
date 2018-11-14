#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define sif(n) scanf("%d",&n)
#define lif(n) scanf("%lld",&n)
#define MAX 1000005
#define MOD 100000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define piii pair<pii,int>
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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};
int kx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int ky[] = {1, -1, 1, -1, 2, 2, -2, -2};

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

/*class info
{
public:
    // variables
    info()//arguments
    {
        //constructor
    }
    bool operator < (info &o)
    {
        //condition
    }
};
*/

int r,c;

int row[10000],col[10000];

bool inBound(int x,int y)
{
    if(x>=0&&x<r&&y>=0&&y<c)
        return (row[x]==false&&col[y]==false);
    else
        return false;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n,ax,ay,x,y,k=0;

    while(scanf("%d%d%d",&r,&c,&n))
    {
        if(!r&&!c&&!n)  break;

        while(n--)
        {
            scanf("%d%d",&x,&y);
            row[x] = true;
            col[y] = true;
        }

        scanf("%d%d",&ax,&ay);
        bool escape = false;

        if(inBound(ax,ay))
            escape = true;
        else
        {
            for(int i=0;i<4;i++)
            if(inBound(ax+dx[i],ay+dy[i]))
            {
                escape = true;
                break;
            }
        }

        printf("Case %d: ",++k);

        (escape) ? puts("Escaped again! More 2D grid problems!") :
                   puts("Party time! Let's find a restaurant!");

        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));

    }
    return 0;
}
