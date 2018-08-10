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
int kx[]={2,2,-2,-2,1,-1,1,-1};
int ky[]={1,-1,1,-1,2,2,-2,-2};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

vector<string>board,no_game;

bool game()
{
    board.clear();
    char line[10];
    for(int i=0;i<8;i++)
    {
        gets(line);
        board.push_back(line);
    }
    if(board==no_game)  return false;
    gets(line);
    return true;
}

bool inBound(int i,int j)
{
    return(i>=0&&i<8&&j>=0&&j<8);
}

bool pawn(int i,int j)
{
    if(board[i][j]=='P')
    {
        if(inBound(i-1,j-1)&&board[i-1][j-1]=='k')  return true;
        else if(inBound(i-1,j+1)&&board[i-1][j+1]=='k')  return true;
        else return false;
    }
    else if(board[i][j]=='p')
    {
        if(inBound(i+1,j-1)&&board[i+1][j-1]=='K')  return true;
        else if(inBound(i+1,j+1)&&board[i+1][j+1]=='K')  return true;
        else return false;
    }
}

bool king(int i,int j)
{
    int x = i, y = j;
    for(int a=0;a<4;a++)
    {
        i = x, j = y;
        while(inBound(i+dx[a],j+dy[a]))
        {
            i+=dx[a], j+=dy[a];
            if(board[x][y]=='k'&&(board[i][j]=='Q'||board[i][j]=='R'))
                return true;
            if(board[x][y]=='K'&&(board[i][j]=='q'||board[i][j]=='r'))
                return true;
            else if(board[i][j]!='.')   break;
        }
    }
    for(int a=4;a<8;a++)
    {
        i = x, j = y;
        while(inBound(i+dx[a],j+dy[a]))
        {
            i+=dx[a], j+=dy[a];
            if(board[x][y]=='k'&&(board[i][j]=='Q'||board[i][j]=='B'))
                return true;
            if(board[x][y]=='K'&&(board[i][j]=='q'||board[i][j]=='b'))
                return true;
            else if(board[i][j]!='.')   break;
        }
    }
    return false;
}

bool knight(int i,int j)
{
    int x = i, y = j;
    for(int a=0;a<8;a++)
    {
        i = x, j = y;
        if(inBound(i+kx[a],j+ky[a]))
        {
            i+=kx[a], j+=ky[a];
            if(board[x][y]=='N' && board[i][j]=='k')
                return true;
            if(board[x][y]=='n' && board[i][j]=='K')
                return true;
        }
    }
    return false;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    for(int i=0;i<8;i++)
        no_game.push_back("........");
    int kase = 1;
    while(game())
    {
        printf("Game #%d: ",kase++);

        bool check = false;

        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j]=='P')    check = pawn(i,j);
                else if(board[i][j]=='N')   check = knight(i,j);
                else if(board[i][j]=='k')   check = king(i,j);
                if(check)   break;
            }
            if(check)   break;
        }
        if(check)  {
            puts("black king is in check.");
            continue;
        }

        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j]=='p')    check = pawn(i,j);
                else if(board[i][j]=='n')   check = knight(i,j);
                else if(board[i][j]=='K')   check = king(i,j);
                if(check)   break;
            }
            if(check)   break;
        }

        if(check)
            puts("white king is in check.");
        else
            puts("no king is in check.");
    }

    return 0;
}
