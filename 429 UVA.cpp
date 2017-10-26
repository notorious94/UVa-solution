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

int BFS(vector< vector<int> > graph, int s, int e)
{
    bool visit[graph.size()];
    int level[graph.size()];
    memset(visit,false,sizeof(visit));
    queue<int>q;
    visit[s]=true;
    level[s]=0;
    q.push(s);

    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(int i=0 ;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(visit[v]==false)
            {
                visit[v]=true;
                level[v]=level[u]+1;
                q.push(v);
            }
            if(visit[e])    return level[e];
        }
    }

    return -1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int test;
    string v;

    cin>>test;
    cin.ignore();
    cin.ignore();

    while(test--)
    {
        vector<string>words;
        map<string, int>loc;
        vector<vector<int> >graph;

        graph.clear();
        bool ara = false;

        while(get_stl(v))
        {
            if(!v[0] || !cin)   break;
            if(v[0]=='*')
            {
                ara = true;
                graph.resize(words.size());

                for(int i=0;i<words.size()-1;i++)
                {
                    for(int j=i+1;j<words.size();j++)
                    {
                        if(words[i].size()!=words[j].size())    continue;
                        else
                        {
                            int c = 0;
                            for(int a=0;words[i][a];a++)
                                if(words[i][a]!=words[j][a])    c++;
                            if(c==1)
                            {
                                graph[i].push_back(j);
                                graph[j].push_back(i);
                            }
                        }
                    }
                }
                for(int i=0;i<words.size();i++)
                    loc[words[i]] = i;
                words.clear();
            }

            else if(ara==false)
                words.push_back(v);

            else if(ara)
            {
                string s,e;
                bool des = false;
                for(int i=0;v[i];i++)
                {
                    if(v[i]==32)
                    {
                        des = true;
                        continue;
                    }
                    if(!des)  s.push_back(v[i]);
                    if(des)   e.push_back(v[i]);
                }
                int S = loc[s];
                int E = loc[e];
                int distance = BFS(graph,S,E);
                cout<<s<<" "<<e<<" "<<distance<<endl;
            }
        }
        if(test!=0) cout<<endl;
    }
    return 0;
}
