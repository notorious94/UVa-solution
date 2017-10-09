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

int dx[] = {2, 2, -2, -2, 1, -1, 1, -1}; /// Direction array
int dy[] = {1, -1, 1, -1, 2, 2, -2, -2}; /// Direction array

int dis[8][8];
bool visit[8][8];

void BFS(int sx,int sy,int ex, int ey)
{
    queue<pii>Q;
    Q.push(pii(sx,sy));
    visit[sx][sy]=true;

    while(Q.size())
    {
        pii u = Q.front();
        Q.pop();

        for(int i=0;i<8;i++)
        {
            int vx = u.first + dx[i];
            int vy = u.second + dy[i];

            if(vx>=0&&vx<8&&vy>=0&&vy<8&&visit[vx][vy]==false)
            {
                visit[vx][vy]=true;
                dis[vx][vy] = dis[u.first][u.second] + 1;
                Q.push(pii(vx,vy));
            }
            if(visit[ex][ey])   return;
        }
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    char s[10],e[10];

    while(scanf("%s%s",s,e)!=EOF)
    {
        memset(dis, 0, sizeof(dis));
        memset(visit, false, sizeof(visit));

        int sx = s[0]-'a';
        int sy = s[1]-'0'-1;

        int ex = e[0]-'a';
        int ey = e[1]-'0'-1;

        BFS(sx,sy,ex,ey);

        printf("To get from %s to %s takes %d knight moves.\n",s,e,dis[ex][ey]);
    }
    return 0;
}
