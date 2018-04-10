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

class holes{
public:
    char c;
    int freq;
    holes(char _, int __)
    {
        c = _,freq = __;
    }
    void p()
    {
        printf("%c: %d\n",c,freq);
    }
    bool operator < (const holes &p) const{
        if(freq!=p.freq)
            return freq>p.freq;
        return c < p.c;
    }
};

vector<string>grid;
int r,c;

bool inBound(int x,int y)
{
    return(x>=0&&x<r&&y>=0&&y<c);
}

void FloodFill(char c,int x,int y)
{
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
            if(inBound(vx,vy)&&grid[vx][vy]==c)
            {
                grid[vx][vy] = '.';
                q.push(pii(vx,vy));
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char s[10000];
    int t,region[26];
    vector<holes>h;
    scanf("%d",&t);

    for(int k=1;k<=t;k++)
    {
        scanf("%d%d",&r,&c);

        grid.clear();
        h.clear();
        mem(region,0);

        for(int i=0;i<r;i++)
        {
            scanf("%s",s);
            grid.push_back(s);
        }

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]!='.')
                {
                    char x = grid[i][j]-'a';
                    FloodFill(grid[i][j],i,j);
                    region[x]++;
                }

        for(int i=0;i<26;i++)
            if(region[i])
                h.push_back(holes(i+'a',region[i]));

        sort(all(h));
        printf("World #%d\n",k);
        for(int i=0;i<h.size();i++)
            h[i].p();
    }

    return 0;
}
