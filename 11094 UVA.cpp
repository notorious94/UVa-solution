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

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int dz[]={0,0,1,-1,-1,1,-1,1};
int r,c;
char land;

bool inBound(int x,int y)
{
    return(x>=0&&x<r&&y>=0&&y<c);
}

vector<string>grid;

int BFS(int sx,int sy)
{
    int scc = 1;
    queue<pii>q;
    q.push(pii(sx,sy));
    grid[sx][sy]='.';
    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if(inBound(vx,vy))
            {
                if(grid[vx][vy]==land)
                {
                    grid[vx][vy] = '.';
                    scc++;
                    q.push(pii(vx,vy));
                }
            }
            else if(i==1||i==3)
            {
                if(i==1)        vy += c; /// <--
                else if(i==3)   vy %= c; /// -->
                if(grid[vx][vy]==land)
                {
                    grid[vx][vy] = '.';
                    scc++;
                    q.push(pii(vx,vy));
                }
            }
        }
    }
    return scc;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[5000];
    int kx,ky;
    while(scanf("%d%d",&r,&c)==2)
    {
        grid.clear();
        for(int i=0;i<r;i++)
        {
            scanf("%s",s);
            grid.push_back(s);
        }
        scanf("%d%d",&kx,&ky);
        land = grid[kx][ky];
        BFS(kx,ky);
        int scc = 0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]==land)
                    scc = max(scc,BFS(i,j));
        printf("%d\n",scc);
    }

    return 0;
}
