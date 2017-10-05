#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

map<string, vector<string> > city;
map<string, vector<string> > :: iterator it;

void bfs(string s, string e)
{
    map<string, bool>visit;
    map<string, string>path;

    for(it = city.begin();it!=city.end();it++)
        visit[it->first]=false;

    queue<string>Q;
    Q.push(s);
    visit[s]=true;
    path[s] = s[0];

    while(Q.size()!=0)
    {
        string u = Q.front();
        Q.pop();

        for(int i=0;i<city[u].size();i++)
        {
            string v = city[u][i];
            if(visit[v]==false)
            {
                visit[v]=true;
                path[v] = path[u] + v[0];
                Q.push(v);
            }
        }

        if(visit[e])    break;
    }

    pf("%s\n",path[e].c_str());
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t,n,q;
    string a,b,s,e;
    sf("%d", &t);

    for(int kase=1;kase<=t;kase++)
    {
        sf("%d%d", &n,&q);

        city.clear();

        while(n--)
        {
            cin>>a>>b;
            city[a].push_back(b);
            city[b].push_back(a);
        }

        while(q--)
        {
            cin>>s>>e;
            bfs(s,e);
        }

        if(kase!=t)
            cout<<endl;

    }
    return 0;
}
