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

int r,c;
vector<string>board;

bool inBound(int x,int y)
{
    return (x>=0&&x<r&&y>=0&&y<c);
}
void Fill(int x,int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    board[x][y] = '#';

    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;

        q.pop();

        for(int i=0;i<4;i++)
        {
            int vx = ux+dx[i];
            int vy = uy+dy[i];

            if(inBound(vx,vy))
            {
                if(board[vx][vy]=='x'||board[vx][vy]=='@')
                {
                    board[vx][vy] = '#';
                    q.push(pii(vx,vy));
                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test,n;
    char b[105];
    scanf("%d",&test);

    for(int k=1;k<=test;k++)
    {
        scanf("%d",&n);
        r=c=n;
        board.clear();

        while(n--)
        {
            scanf("%s",b);
            board.push_back(b);
        }

        int ship = 0;

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(board[i][j]=='x')
                {
                    Fill(i,j);
                    ship++;
                }

        printf("Case %d: %d\n",k,ship);
    }
    return 0;
}

