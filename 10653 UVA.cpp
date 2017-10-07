#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int dx[]={1,-1, 0, 0};
int dy[]={0, 0, 1,-1};

int Distance[1000][1000];
bool   visit[1000][1000];
int grid[1000][1000];
int row, col;

void flush()
{
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            grid[i][j]=0;
            visit[i][j]=false;
            Distance[i][j]=0;
        }
}

void BFS(int sx, int sy,int ex, int ey)
{
    queue<pii>Q;

    visit[sx][sy]=true;
    Distance[sx][sy]=0;

    Q.push(pii(sx,sy));

    while(Q.size()!=0)
    {
        pii u = Q.front();
        Q.pop();

        for(int i=0;i<4;i++)
        {
            int vx = u.first + dx[i];
            int vy = u.second + dy[i];;

            if( vx>=0&&vx<row && vy>=0&&vy<col && grid[vx][vy]!=-1 && visit[vx][vy]==false)
            {
                visit[vx][vy] = true;
                Distance[vx][vy] = Distance[u.first][u.second] + 1;
                Q.push(pii(vx, vy));
            }

            if(visit[ex][ey]==true)
                return;
        }
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int bomb,x,y,q;
    int sx, sy, ex, ey;

    while(scanf("%d%d",&row,&col)!=EOF)
    {
        if(!row&&!col)
            break;

        scanf("%d",&q);

        while(q--)
        {
            scanf("%d%d",&x, &bomb);

            while(bomb--)
            {
                scanf("%d", &y);
                grid[x][y] = -1;
            }

        }

        scanf("%d%d", &sx, &sy);
        scanf("%d%d", &ex, &ey);

        BFS(sx, sy, ex, ey);

        printf("%d\n",Distance[ex][ey]);

        flush();
    }

    return 0;
}
