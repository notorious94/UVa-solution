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

int r[50][50],t[50][50];

void reset(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            r[i][j] = (i==j) ? 0 : INF;
            t[i][j] = (i==j) ? 0 : INF;
        }
    }
}

void floyed(int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(r[i][k]!=INF && r[k][j]!=INF && t[i][k]!=INF &&t[k][j]!=INF)
                {
                    if(t[i][k]+t[k][j]<t[i][j] || (t[i][k]+t[k][j]==t[i][j] && r[i][k]+r[k][j]<r[i][j]) )
                    {
                        t[i][j] = t[i][k]+t[k][j];
                        r[i][j] = r[i][k]+r[k][j];
                    }
                }
}

void input(int n)
{
    int a,b,c,d;
    while(n--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(t[a][b]>c || (t[a][b]==c && r[a][b]>d) )
        {
            t[a][b] = t[b][a] = c;
            r[a][b] = r[b][a] = d;
        }
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test,x,y,q,s,d;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d%d",&x,&y);

        reset(x);
        input(y);
        floyed(x);

        scanf("%d",&q);

        while(q--)
        {
            scanf("%d%d",&s,&d);
            if(r[s][d]!=INF&&t[s][d]!=INF)
                pf("Distance and time to reach destination is %d & %d.\n",r[s][d],t[s][d]);
            else
                pf("No Path.\n");
        }

        if(test)
            pf("\n");
    }
    return 0;
}
