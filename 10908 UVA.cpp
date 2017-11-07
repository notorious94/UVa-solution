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

string grid[500];
int m,n;
int ax,ay;
int bx,by;
int cx,cy;
int dx,dy;

bool chk(int x, int y)
{
    return (x>=0 && x<m && y>=0 && y<n) ? true : false;
}

bool square(char item)
{
    if(!chk(ax,ay)||!chk(bx,by)||!chk(cx,cy)||!chk(dx,dy))
        return false;

    int p,q;
    int u,v;

    for(p = ax,q=ay;p<=bx&&q<=by;q++) /// A -> B
        if(grid[p][q]!=item)    return false;

    for(p = ax,q=ay;p<=cx&&q<=cy;p++) /// A -> C
        if(grid[p][q]!=item)    return false;

    for(p = cx,q=cy;p<=dx&&q<=dy;q++) /// C -> D
        if(grid[p][q]!=item)    return false;

    for(p = bx,q=by;p<=dx&&q<=dy;p++) /// B to D
        if(grid[p][q]!=item)    return false;

    return true;

}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int t,q,x,y;
    cin>>t;

    while(t--)
    {
        cin>>m>>n>>q;
        cout<<m<<" "<<n<<" "<<q<<endl;

        for(int i=0;i<m;i++)
            cin>>grid[i];

        while(q--)
        {
            cin>>x>>y;

            ax = x-1;
            ay = y-1;

            bx = x-1;
            by = y+1;

            cx = x+1;
            cy = y-1;

            dx = x+1;
            dy = y+1;

            int level = 0;

            while(square(grid[x][y]))
            {
                level++;

                ax -=1;
                ay -=1;

                bx -=1;
                by +=1;

                cx +=1;
                cy -=1;

                dx +=1;
                dy +=1;
            }

            cout<<level*2+1<<endl;
        }
    }

    return 0;
}
