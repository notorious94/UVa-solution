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

int grid[11][11];
string g[11];
int r,c;
int x, y,step;

bool inBound()
{
    return (x>=0&&x<r && y>=0&&y<c) ? true : false;
}

void init()
{
    mem(grid,-1);
    step = 0;
    for(int i=0;i<r;i++)    cin>>g[i];
}

void move()
{

    int loop = -1, loopStep = -1;
    bool exit = false;

    while(true)
    {
        if(g[x][y]=='N')
        {
            --x;
            ++step;
            if(inBound())
            {
                if(grid[x][y]!=-1)
                {
                    loopStep = grid[x][y];
                    loop = step - grid[x][y];
                    break;
                }
                else    grid[x][y] = step;
            }
            else
            {
                exit = true;
                break;
            }
        }
        else if(g[x][y]=='S')
        {
            ++x;
            ++step;
            if(inBound())
            {
                if(grid[x][y]!=-1)
                {
                    loopStep = grid[x][y];
                    loop = step - grid[x][y];
                    break;
                }
                else    grid[x][y] = step;
            }
            else
            {
                exit = true;
                break;
            }
        }
        else if(g[x][y]=='E')
        {
            ++y;
            ++step;
            if(inBound())
            {
                if(grid[x][y]!=-1)
                {
                    loopStep = grid[x][y];
                    loop = step - grid[x][y];
                    break;
                }
                else    grid[x][y] = step;
            }
            else
            {
                exit = true;
                break;
            }
        }
        else if(g[x][y]=='W')
        {
            --y;
            ++step;
            if(inBound())
            {
                if(grid[x][y]!=-1)
                {
                    loopStep = grid[x][y];
                    loop = step - grid[x][y];
                    break;
                }
                else    grid[x][y] = step;
            }
            else
            {
                exit = true;
                break;
            }
        }
    }

    if(exit)
        pf("%d step(s) to exit\n",step);
    else
        pf("%d step(s) before a loop of %d step(s)\n",loopStep,loop);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int p;
    while(scanf("%d%d%d",&r,&c,&p)==3)
    {
        if(!r && !c && !p)  break;
        init();
        x = 0;
        y = p-1;
        grid[x][y] = 0;
        move();
    }

    return 0;
}
