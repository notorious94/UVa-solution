#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
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

char cell[1001][1001];
int row, col;

void BFS(int x, int y)
{
    queue<pii>Q;

    Q.push(pii(x,y));
    cell[x][y]= '*' ;

    while(Q.size())
    {
        pii u = Q.front();
        Q.pop();

        for(int i=0;i<8;i++)
        {
            int vx = u.first + dx[i];
            int vy = u.second + dy[i];

            if( vx>=1 && vx<=row && vy>=1 && vy<=col && cell[vx][vy]=='@')
            {
                cell[vx][vy]='*';
                Q.push(pii(vx,vy));
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    while(sf("%d %d", &row, &col))
    {
        if(!row&&!col)  break;

        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                cin>>cell[i][j];

        int ans=0;

        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                if(cell[i][j]=='@')
                {
                    ans++;
                    BFS(i,j);
                }

        printf("%d\n",ans);
    }
    return 0;
}
