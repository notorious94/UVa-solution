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

int dl[]={ 0, 0, 0, 0,-1, 1};
int dx[]={-1, 0, 0, 1, 0, 0};
int dy[]={ 0,-1, 1, 0, 0, 0};

struct in
{
    int l,x,y;
    in(int a,int b, int c)
    {
        l=a;
        x=b;
        y=c;
    }
};

int level,row,col;
char G[31][31][31];
int dis[31][31][31];
bool visit[31][31][31];

void flush()
{
    for(int l=1;l<=level;l++)
        for(int i=0;i<=row;i++)
            for(int j=0;j<=col;j++)
            {
                dis[l][i][j] = -1;
                visit [l][i][j] = false;
            }
}

int BFS_3D(int sl,int sx,int sy,int el,int ex,int ey)
{
    dis[sl][sx][sy] = 0;
    visit[sl][sx][sy] = true;

    queue<in>Q;
    Q.push(in(sl,sx,sy));

    while(Q.size())
    {
        in u = Q.front();
        Q.pop();

        for(int i=0;i<6;i++)
        {
            int vl = u.l + dl[i];
            int vx = u.x + dx[i];
            int vy = u.y + dy[i];

            if(vl>=1&&vl<=level && vx>=1&&vx<=row && vy>=1&&vy<=col && visit[vl][vx][vy]==false && G[vl][vx][vy]!='#')
            {
                visit[vl][vx][vy] = true;
                dis[vl][vx][vy] = dis[u.l][u.x][u.y] + 1;
                Q.push(in(vl,vx,vy));
            }
            if(visit[el][ex][ey])   return dis[el][ex][ey];
        }
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int sl,si,sj,el,ei,ej;

    while(cin>>level>>row>>col)
    {
        if(!level&&!row&&!col)
            break;

        flush();

        for(int x = 1;x<=level;x++)
            for(int i =1;i<=row;i++)
                for(int j=1;j<=col;j++)
                {
                    cin>>G[x][i][j];

                    if(G[x][i][j]=='S')
                    {
                        sl = x;
                        si = i;
                        sj = j;
                    }
                    else if(G[x][i][j]=='E')
                    {
                        el = x;
                        ei = i;
                        ej = j;
                    }
                }
        int path = BFS_3D(sl,si,sj,el,ei,ej);

        if(path==-1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n",path);
    }

    return 0;
}
