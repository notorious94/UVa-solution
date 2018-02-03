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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

/// M A C R O Ends Here

string grid[100];
int r,c,x,y,sticker,total;
char tmp,d,command[50005];

bool inBound(int i, int j)
{
    return ((i>=0&&i<r) && (j>=0&&j<c)) ? true : false;
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
}

void process()
{
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
        process();
    }
    
    return 0;
}
