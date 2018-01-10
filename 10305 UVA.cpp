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
vector<int>adj[101];
deque<int>top_sort;

bool visit[101];

void DFS(int s);

void DFS_call(int n)
{
    mem(visit,false);
    for(int i=1;i<=n;i++)
        if(!visit[i])
            DFS(i);
}

void DFS(int s)
{
    visit[s]=true;

    for(int i=0;i<adj[s].size();i++)
    {
        int v = adj[s][i];
        if(!visit[v])
            DFS(v);
    }
    top_sort.push_front(s);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    int a,b;

    while(scanf("%d%d",&n,&m))
    {
        if(!n&&!m)  break;

        for(int i=1;i<=n;i++)
            adj[i].clear();

        while(m--)
        {
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
        }

        DFS_call(n);

        for(int i=0;i<n;i++)
        {
            pf("%d%c",top_sort.front(),(i==n-1) ? '\n' : ' ');
            top_sort.pop_front();
        }

    }
    return 0;
}
