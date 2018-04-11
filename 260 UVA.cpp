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

int dx[]={-1,-1,0,0,1,1};
int dy[]={-1,0,-1,1,0,1};
bool visit[205][205];
vector<string>grid;
int r;

bool inBound(int x,int y)
{
    return(x>=0&&x<r&&y>=0&&y<r);
}

bool BFS(int sx,int sy)
{
    queue<pii>q;
    visit[sx][sy] = true;
    q.push(pii(sx,sy));
    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(int i=0;i<6;i++)
        {
            int vx = ux+dx[i];
            int vy = uy+dy[i];
            if(inBound(vx,vy)&&grid[vx][vy]=='b'&&!visit[vx][vy])
            {
                if(vx==r-1) return true;
                visit[vx][vy] = true;
                q.push(pii(vx,vy));
            }
        }
    }
    return false;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int kase = 0;
    char s[500];
    while(scanf("%d",&r))
    {
        if(!r)  break;
        grid.clear();
        printf("%d ",++kase);
        for(int i=0;i<r;i++)
        {
            scanf("%s",s);
            grid.push_back(s);
        }
        bool white = true;
        for(int i=0;i<r;i++)
        {
            if(grid[0][i]=='b')
            {
                mem(visit,false);
                bool black = BFS(0,i);
                if(black)
                {
                    white = false;
                    break;
                }
            }
        }
        (white) ? puts("W") : puts("B");
    }

    return 0;
}
