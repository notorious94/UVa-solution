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

void BFS(map<string,vector<string> >city, string s, string e)
{
    map<string, bool> visit;
    map<string, int> level;
    map<string, string> path;

    map<string,vector<string> > :: iterator it;

    for(it = city.begin();it!=city.end();it++)
    {
        visit[it->first] = false;
        level[it->first] = -1;
    }

    queue<string>q;
    q.push(s);
    path[s]=s;
    visit[s]=true;
    level[s]=0;

    while(q.size()!=0)
    {
        string u = q.front();
        q.pop();

        for(int i=0;i<city[u].size();i++)
        {
            string v = city[u][i];
            if(visit[v]==false)
            {
                visit[v]=true;
                level[v]=level[u]+1;
                path[v]=path[u]+" "+v;
                q.push(v);
            }
        }

        if(visit[e]==true)
            break;
    }

    if(level[e]==-1||level[e]==0)
        cout<<"No route"<<endl;

    else
    {
        string temp;
        queue<string>ans;

        for(int i=0;path[e][i]!=0;i++)
        {
            if(path[e][i]==32)
            {
                ans.push(temp);
                temp.clear();
            }
            else
                temp+=path[e][i];
        }

        if(temp.size())
            ans.push(temp);
        temp.clear();
        ans.pop();
        string a=s,b;
        while(ans.size()!=0)
        {
            b = ans.front();
            cout<<a<<" "<<b<<endl;
            a = b;
            ans.pop();
        }
    }

}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n,kase=0;
    string a,b,S,E;
    map<string, vector<string> > city;

    while(sf("%d", &n)!=EOF)
    {
        kase++;

        if(kase>1)
            cout<<endl;

        while(n--)
        {
            cin>>a>>b;
            city[a].push_back(b);
            city[b].push_back(a);
        }

        cin>>S>>E;
        BFS(city,S,E);
        city.clear();

    }
    return 0;
}
