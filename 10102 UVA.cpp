#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int m;

vector<string>grid;
int level[100][100];
bool visit[100][100];

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};

bool inBound(int x,int y)
{
    return(x>=0&&x<m&&y>=0&&y<m);
}

int BFS(int i,int j)
{
    memset(visit,0,sizeof(visit));
    level[i][j] = 0;
    visit[i][j] = true;
    //int max_dist = INT_MIN;

    queue<pair<int,int> >q;

    q.push({i,j});

    while(q.size())
    {
        pii u = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int vx = u.first+dx[i];
            int vy = u.second+dy[i];
            if(inBound(vx,vy)&&visit[vx][vy]==false)
            {
                visit[vx][vy] = true;
                level[vx][vy] = level[u.first][u.second]+1;

                if(grid[vx][vy]=='3')
                    return level[vx][vy];
                q.push({vx,vy});
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char s[500];
    while(scanf("%d",&m)==1)
    {
        grid.clear();
        for(int i=0;i<m;i++)
        {
            scanf("%s",s);
            grid.push_back(s);
        }

        int ans = INT_MIN;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans = max(ans,BFS(i,j));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
