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

int graph[101][101];

int n;

void flush()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            (i==j) ?  graph[i][j]=0 : graph[i][j] = 99999;
}

void floyd_warshal()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(graph[i][k]+graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k]+graph[k][j];

}

int get_answer()
{
    int max = 0;

    for(int i=1;i<=n;i++)
        if(max<graph[1][i])
            max = graph[1][i];

    return max;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    string s;

    while(scanf("%d",&n)!=EOF)
    {
        flush();
        for(int r=2;r<=n;r++)
        {
            for(int c=1;c<r;c++)
            {
                cin>>s;
                if(s[0]!='x')
                {
                    int v = atoi(s.c_str());
                    graph[r][c] = v;
                    graph[c][r] = v;
                }
            }
        }

        floyd_warshal();

        int ans = get_answer();

        printf("%d\n",ans);

    }

    return 0;
}
