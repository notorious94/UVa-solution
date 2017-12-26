#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 9999999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

int g[101][101];

void setValue(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            g[i][j] = (i==j) ? 0 : INF;
        }
    }
}

void floyd(int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
}

int makeAnswer(int n)
{
    vector<int>point;

    for(int i=6;i<=n;i++)
        if(g[i][1]==g[i][2]&&g[i][3]==g[i][4]&&g[i][4]==g[i][5]&&g[i][1]==g[i][5]&&g[i][1]<INF)
            point.push_back(i);

    if(point.size()==0)
        return -1;

    else
    {
        int ans,D=INF;
        for(int j = 0;j<point.size();j++)
        {
            int d = -1;
            for(int i=1;i<=n;i++)
                d = max(d, g[point[j]][i]);
            if(d<D)     D = d;
        }
        return (D==INF) ? -1 : D;
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int l,d,x,y,c;

    scanf("%d",&t);
    for(int m=1;m<=t;m++)
    {
        pf("Map %d: ",m);

        scanf("%d%d",&l,&d);

        setValue(l);

        while(d--)
        {
            scanf("%d%d%d",&x,&y,&c);
            if(c<g[x][y])
            {
                g[x][y] = c;
                g[y][x] = c;
            }
        }

        floyd(l);
        int ans = makeAnswer(l);
        pf("%d\n",ans);
    }
    return 0;
}
