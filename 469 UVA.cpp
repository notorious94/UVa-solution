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

vector<string>g;
int r,c;
bool visit[102][102];

int bfs(int i, int j)
{
    memset(visit, false, sizeof(visit));
    queue<pii>q;
    q.push(pii(i,j));
    visit[i][j] = true;

    int count = 0;

    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;

        q.pop();

        for(int i = 0; i<8 ;i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(vx>=0 && vx < r && vy>=0 && vy < c && g[vx][vy]!='L')
            {
                if(visit[vx][vy]==false)
                {
                    count++;
                    visit[vx][vy] = true;
                    q.push(pii(vx,vy));
                }
            }
        }
    }

    return ++count;

}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int x,y,t;
    string s;

    cin>>t;
    cin.ignore();
    cin.ignore();

    while(t--)
    {
        while(get_stl(s))
        {
            if(!s[0]||!cin)
            {
                g.clear();
                break;
            }
            if(isdigit(s[0]))
            {
                string temp;

                r = g.size();
                c = g[0].size();

                for(int i=0;s[i];i++)
                {
                    if(s[i]==32)
                    {
                        x = atoi(temp.c_str());
                        temp.clear();
                        continue;
                    }
                    temp.push_back(s[i]);
                }
                y = atoi(temp.c_str());
                cout<<bfs(x-1,y-1)<<endl;
            }
            else g.push_back(s);
        }
        if(t)   cout<<endl;
    }
    return 0;
}
