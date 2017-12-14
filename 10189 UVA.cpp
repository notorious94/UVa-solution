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

int m,n;

char grid[101][101];
int ans[101][101];

bool check(int x, int y)
{
    if(x>=0 && x<m && y>=0 && y<n)
        return true;
    else return false;
}

int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int field=0;

    while(scanf("%d%d",&m,&n))
    {

        if(!m&&!n)  break;

        ++field;
        if(field>1) pf("\n");

        for(int i=0;i<m;i++)    scanf("%s",grid[i]);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                int x,y,count = 0;
                for(int k=0;k<8;k++){
                    x = i+dx[k];
                    y = j+dy[k];

                    if(check(x,y))
                        if(grid[x][y]=='*')
                            count++;
                }   ans[i][j] = count;
            }

        pf("Field #%d:\n",field);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                (grid[i][j]=='*') ? pf("*") : pf("%d",ans[i][j]);
            }
            pf("\n");
        }
    }

    return 0;
}
