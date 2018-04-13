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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};

vector<string>grid;
int r,c;

bool inBound(int x,int y)
{
    return(x>=0&&x<r&&y>=0&&y<c);
}

int BFS(int sx,int sy)
{
    queue<pii>q;
    q.push(pii(sx,sy));
    grid[sx][sy] = '0';
    int scc = 1;
    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int vx = ux+dx[i];
            int vy = uy+dy[i];
            if(inBound(vx,vy)&&grid[vx][vy]=='1')
            {
                scc++;
                q.push(pii(vx,vy));
                grid[vx][vy] = '0';
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

    char s[50];
    int t;
    scanf("%d\n\n",&t);
    while(t--)
    {
        grid.clear();
        while(gets(s))
        {
            if(!s[0])   break;
            grid.push_back(s);
        }
        r = grid.size();
        c = grid[0].size();
        int bloob = 0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]=='1')
                    bloob = max(bloob,BFS(i,j));
        pif(bloob);
        if(t)   puts("");
    }

    return 0;
}
