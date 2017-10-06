#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int INF = 999999;
int grid[101][101];
double Count;
double sum;

void Clear()
{

    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++){

            if(i==j)    grid[i][j]=0;
            else        grid[i][j]=INF;
        }

}

void floyd_warshal(int s, int e)
{
    for(int k=s;k<=e;k++)
            for(int i=s;i<=e;i++)
                for(int j=s;j<=e;j++)
                    grid[i][j]= min(grid[i][j], grid[i][k]+grid[k][j]);
}

double get_ans(int s, int e)
{

    Count = 0;
    sum = 0;

    for(int i=s;i<=e;i++)
        for(int j=s;j<=e;j++)
            if(grid[i][j]!=INF&&grid[i][j]!=0)
            {
                Count++;
                sum+=grid[i][j];
            }

    double ans = sum/Count;
    return ans;

}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int a,b,kase=0;

    while(true)
    {
        scanf("%d%d", &a,&b);

        if(!a&&!b)  break;

        Clear();
        kase++;

        grid[a][b]=1;

        int s = min(a,b);
        int e = max(a,b);

        while(true)
        {
            scanf("%d%d", &a,&b);

            if(!a&&!b)  break;

            grid[a][b]=1;
            s = min(s, min(a,b));
            e = max(e, max(a,b));
        }

        floyd_warshal(s,e);

        double ans = get_ans(s,e);

        printf("Case %d: average length between pages = %.3lf clicks\n",kase,ans);

    }
    return 0;
}
