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

string grid[100];
int r,c,x,y;
char d,command[50005];
int sticker,total;

bool inBound(int i, int j)
{
    return (i>=0&&i<r && j>=0&&j<c) ? true : false;
}

void direct(char c)
{
    if(d=='N')       (c=='D') ? d = 'L' : d = 'O';
    else if(d=='S')  (c=='D') ? d = 'O' : d = 'L';
    else if(d=='L')  (c=='D') ? d = 'S' : d = 'N';
    else if(d=='O')  (c=='D') ? d = 'N' : d = 'S';
}

void forward()
{
    if(d=='N')
    {
        if(inBound(x-1,y) && grid[x-1][y]!='#')
        {
            if(grid[--x][y]=='*')
            {
                sticker++;
                grid[x][y] = '.';
            }
        }
    }
    else if(d=='S')
    {
        if(inBound(x+1,y) && grid[x+1][y]!='#')
        {
            if(grid[++x][y]=='*')
            {
                sticker++;
                grid[x][y] = '.';
            }
        }
    }
    else if(d=='L')
    {
        if(inBound(x,y+1) && grid[x][y+1]!='#')
        {
            if(grid[x][++y]=='*')
            {
                sticker++;
                grid[x][y] = '.';
            }
        }
    }
    else if(d=='O')
    {
        if(inBound(x,y-1) && grid[x][y-1]!='#')
        {
            if(grid[x][--y]=='*')
            {
                sticker++;
                grid[x][y] = '.';
            }
        }
    }
}
void input()
{
    char tmp;
    sticker=total=0;
    for(int i=0;i<r;i++)
    {
        grid[i].clear();
        for(int j=0;j<c;j++)
        {
            scanf(" %c",&tmp);
            if(tmp=='*')    total++;
            if(tmp=='N'||tmp=='S'||tmp=='L'||tmp=='O')
            {
                x = i;
                y = j;
                d = tmp;
                tmp = '.';
            }
            grid[i]+=tmp;
        }
    }
    scanf("%s",command);
    for(int i=0;sticker<total&&command[i];i++)
    {
        if(command[i]=='F') forward();
        else    direct(command[i]);
    }
    pif(sticker);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(sf("%d%d%d",&r,&c,&n))
    {
        if(!r&&!c&&!n)  break;
        input();
    }
    return 0;
}
