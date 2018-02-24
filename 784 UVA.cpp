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
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};

vector<string>g;

bool inBound(int x, int y)
{
    if(x<0 || x>=g.size() || y<0)
        return false;
    if(x>=0 && x<g.size() && y>=0 && y<g[x].size())
        return true;
    return false;
}

void BFS(int i, int j)
{
    g[i][j]='#';
    queue<pii>q;
    q.push(pii(i,j));
    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if(inBound(vx,vy))
            {
                if(g[vx][vy]==' ')
                {
                    g[vx][vy] = '#';
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
    char s[5000];
    int t;
    scanf("%d\n",&t);
    while(t)
    {
        gets(s);
        if(s[0]=='_')
        {
            t--;
            for(int i=0;i<g.size();i++)
                for(int j=0;j<g[i].size();j++)
                    if(g[i][j]=='*')
                        BFS(i,j);
            for(int i=0;i<g.size();i++)
                printf("%s\n",g[i].c_str());
            printf("%s\n",s);
            g.clear();
        }
        else    g.push_back(s);
    }

    return 0;
}
