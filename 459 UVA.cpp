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
int dz[]={0,0,1,-1,-1,1,-1,1};

bool visit[30];

void BFS(vector<int> graph[], int s,int n)
{
    visit[s] = true; /// Updating Visit List

    queue<int>q;

    q.push(s);

    while(q.size())
    {
        int u = q.front();
        q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(visit[v]==false)
            {
                visit[v]  = true; /// Adjacent Node got visited
                q.push(v);
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    string s;
    int t,n,x,y;

    cin>>t;

    cin.ignore();
    cin.ignore();

    while(t--)
    {
        get_stl(s);

        n = s[0]-'A'+1;
        vector<int> graph[n];

        memset(visit, false, sizeof(visit));

        while(get_stl(s))
        {
            if(!s[0]||!cin)     break;

            x = s[0]-'A';
            y = s[1]-'A';

            graph[x].push_back(y);
            graph[y].push_back(x);

        }

        int count = 0;

        for(int i=0;i<n;i++)
        	if(visit[i]==false)
            {
                BFS(graph, i,n);
                count++;
            }
        cout<<count<<endl;
        if(t)   cout<<endl;

    }

    return 0;
}
