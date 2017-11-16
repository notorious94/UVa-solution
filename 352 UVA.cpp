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

int dimension;
vector<string>graph;

void BFS(int x, int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    graph[x][y]='0';

    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;

        q.pop();

        for(int i=0;i<8;i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(vx>=0 && vx < dimension && vy>=0 && vy< dimension && graph[vx][vy]!='0')
            {
                graph[vx][vy] = '0';
                q.push(pii(vx, vy));
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
    char s[MAX];
    int kase = 0;

    while(scanf("%d", &dimension)!=EOF)
    {
        kase++;

        for(int i=0;i<dimension;i++)
        {
            scanf("%s",s);
            graph.push_back(s);
        }

        int eagles = 0;

        for(int i=0;i<dimension;i++)
            for(int j=0;j<dimension;j++)
                if(graph[i][j]=='1')
                {
                    BFS(i,j);
                    eagles++;
                }

        graph.clear();
        printf("Image number %d contains %d war eagles.\n",kase,eagles);
    }
    return 0;
}
