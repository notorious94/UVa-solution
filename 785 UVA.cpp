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
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

vector<string>grid;

bool inBound(int x, int y)
{
    return (x>=0 && x<grid.size() && y>=0 && y<grid[x].size()) ? true : false;
}

void BFS(int i, int j)
{
    char c = grid[i][j];
    queue<pii>q;
    q.push(pii(i,j));
    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if(inBound(vx,vy) && grid[vx][vy]==32)
            {
                grid[vx][vy] = c;
                q.push(pii(vx,vy));
            }
        }
    }
}

void check()
{
    int a[256];
    mem(a,0);
    int f=0;
    char c;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j]!=32)
            {
                a[grid[i][j]]++;
                if(a[grid[i][j]]>f)
                {
                    f = a[grid[i][j]];
                    c = grid[i][j];
                }
            }
        }
    }

    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[i].size();j++)
            if(grid[i][j]!=c && grid[i][j]!=32)
                BFS(i,j);
}

void print(char s[])
{
    for(int i=0;i<grid.size();i++)
        printf("%s\n",grid[i].c_str());
    printf("%s\n",s);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    char s[5000];
    while(gets(s))
    {
        if(s[0]=='_')
        {
            check();
            print(s);
            grid.clear();
            continue;
        }
        grid.push_back(s);
    }
    return 0;
}
