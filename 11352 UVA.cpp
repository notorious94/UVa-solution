#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define p_b push_back
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >

typedef long long ll;
typedef unsigned long long ull;

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};
int kx[]= {2,2,-2,-2,1,-1,1,-1};
int ky[]= {1,-1,1,-1,2,2,-2,-2};

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

int r,c;

bool inBound(int x,int y)
{
    return(x>=0&&x<r&&y>=0&&y<c);
}

string board[101];
int level[101][101];
bool visit[101][101];

bool bfs(int sx,int sy,int tx,int ty)
{
    mem(visit,false);
    level[sx][sy] = 0;
    visit[sx][sy] = true;
    queue<pii>q;
    q.push({sx,sy});
    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int vx = ux+dx[i];
            int vy = uy+dy[i];
            if(inBound(vx,vy)&&visit[vx][vy]==false&&board[vx][vy]!='Z'&&board[vx][vy]!='X')
            {
                visit[vx][vy]=true;
                level[vx][vy] = 1 + level[ux][uy];
                q.push({vx,vy});
            }
            if(visit[tx][ty]==true)
                return true;
        }
    }
    return false;
}

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t;

    cin>>t;

    while(t--)
    {
        cin>>r>>c;
        for(int i=0;i<r;i++)
            cin>>board[i];
        bool gameOver = false;
        int sx,sy,tx,ty;
        for(int i=0;!gameOver&&i<r;i++)
        {
            for(int j=0;!gameOver&&j<c;j++)
            {
                if(board[i][j]=='A')
                    sx = i,sy = j;
                else if(board[i][j]=='B')
                    tx = i,ty = j;
                else if(board[i][j]=='Z')
                {
                    for(int k=0;!gameOver&&k<8;k++)
                    {
                        int x = i+kx[k];
                        int y = j+ky[k];
                        if(inBound(x,y))
                        {
                            if(board[x][y]=='.')
                                board[x][y]='X';
                        }

                    }
                }
            }
        }
        if(bfs(sx,sy,tx,ty))
            printf("Minimal possible length of a trip is %d\n",level[tx][ty]);
        else
            puts("King Peter, you can't go now!");
    }
    return 0;
}
