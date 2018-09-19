#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define sif(n) scanf("%d",&n)
#define lif(n) scanf("%lld",&n)
#define MAX 1000005
#define MOD 100000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define piii pair<pii,int>
#define p_b push_back
#define ff first
#define ss second
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >

typedef long long ll;
typedef unsigned long long ull;

enum COLOR { W = 0, G = 1, B = 2};

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};
int kx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int ky[] = {1, -1, 1, -1, 2, 2, -2, -2};

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

vector<string>board;
string b;

int r,c;

bool inBound(int i,int j)
{
    return(i>=0&&i<r&&j>=0&&j<c);
}

void DFS(int ux,int uy)
{
    board[ux][uy] = '.';
    for(int i=0;i<4;i++)
    {
        int vx = ux + dx[i];
        int vy = uy + dy[i];
        if(inBound(vx,vy)&&board[vx][vy]=='#')
            DFS(vx,vy);
    }
}

int BFS(int i,int j)
{
    queue<pii>q1;
    vector<pii>q2;

    if(board[i][j]=='X')
    {
        q2.push_back(pii(i,j));
        board[i][j] = '#';
    }
    else
        board[i][j] = '.';

    q1.push(pii(i,j));
    while(q1.size())
    {
        int ux = q1.front().ff;
        int uy = q1.front().ss;
        q1.pop();
        for(int i=0;i<4;i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if(inBound(vx,vy)&&(board[vx][vy]=='*'||board[vx][vy]=='X'))
            {
                if(board[vx][vy]=='X')
                {
                    board[vx][vy] = '#';
                    q2.push_back(pii(vx,vy));
                }
                else
                    board[vx][vy] = '.';
                q1.push(pii(vx,vy));
            }
        }
    }
    int dice = 0;
    for(int i=0;i<q2.size();i++)
    {
        int x = q2[i].ff;
        int y = q2[i].ss;
        if(board[x][y]=='#')
        {
            dice++;
            DFS(x,y);
        }
    }
    return dice;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int kase = 1;
    while(scanf("%d%d",&c,&r)==2)
    {
        if(!r&&!c)  break;
        vector<int>dice;
        board.clear();
        for(int i=0;i<r;i++)
        {
            cin>>b;
            board.push_back(b);
        }

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='*'||board[i][j]=='X')
                {
                    int d = BFS(i,j);
                    dice.push_back(d);
                }
            }
        }
        sort(all(dice));
        printf("Throw %d\n",kase++);
        for(int i=0;i<dice.size();i++)
        {
            if(i==0)
                printf("%d",dice[i]);
            else
                printf(" %d",dice[i]);
        }
        puts("\n");
    }
    return 0;
}
