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

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
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

vector<string>grid;
int r,c;

bool inBound(int x,int y)
{
    return(x>=0&&x<r&&y>=0&&y<c);
}

int FloodFill(int x,int y)
{
    int c = 1;
    queue<pii>q;
    q.push(pii(x,y));
    grid[x][y] = '.';
    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int vx = ux+dx[i];
            int vy = uy+dy[i];
            if(inBound(vx,vy)&&grid[vx][vy]=='0')
            {
                c++;
                grid[vx][vy] = '1';
                q.push(pii(vx,vy));
            }
        }
    }
    return c;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[10000];
    int t,x,y;
    scanf("%d\n\n",&t);

    for(int k=1;k<=t;k++)
    {
        gets(s);
        grid.clear();
        sscanf(s,"%d%d",&x,&y);
        while(gets(s))
        {
            if(s[0]==0)
                break;
            grid.push_back(s);
        }
        r = grid.size();
        c = grid[0].size();
        printf("%d\n",FloodFill(x-1,y-1));
        if(k!=t)
            puts("");
    }
    return 0;
}
