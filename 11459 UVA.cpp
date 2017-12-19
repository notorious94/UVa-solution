#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int board[121];
int player[1000001];

void build(int a)
{
    for(int i=1;i<=120;i++)
    {
        if(i>=100)  board[i] = 100;
        else        board[i] = i;
    }

    for(int i=1;i<=a;i++)
        player[i] = 1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,a,b,c,x,y,step;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        build(a);

        while(b--)
        {
            scanf("%d%d",&x,&y);
            board[x] = y;
        }

        bool game = true;

        for(int p=1,i=1;i<=c;p++,i++)
        {
            scanf("%d",&step);
            if(game)
            {
                if(p>a)     p = 1;
                player[p]=board[step+player[p]];
                if(player[p]>=100)  game = false;
            }
        }

        for(int i=1;i<=a;i++)
            pf("Position of player %d is %d.\n",i,player[i]);
    }

    return 0;
}
