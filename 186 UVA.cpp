#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF 9999999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

int grid[101][101],path[101][101];
map<string,int>ID;
map<int,string>city;
map<pii,string>road;
vector<int>loc;

void reset(int n=100)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            grid[i][j] = (i==j) ? 0 : INF;
            path[i][j] = i;
        }
    }
}

void floyedWarshall(int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(grid[i][k]+grid[k][j]<grid[i][j])
                {
                    grid[i][j] = grid[i][k] + grid[k][j];
                    path[i][j] = path[k][j];
                }
            }
}

void find_path(int s,int d)
{
    if(s==d)
    {
        loc.push_back(s);
        return;
    }
    find_path(s, path[s][d]);
    loc.push_back(d);
}

void header()
{
    pf("From                 To                   Route      Miles\n");
    for(int i=1;i<=20;i++)
        pf("-");
    pf(" ");
    for(int i=1;i<=20;i++)
        pf("-");
    pf(" ");
    for(int i=1;i<=10;i++)
        pf("-");
    pf(" ");
    for(int i=1;i<=5;i++)
        pf("-");
    pf("\n");
}

void footer()
{
    for(int i=1;i<=53;i++)
        pf(" ");
    for(int i=1;i<=5;i++)
        pf("-");
    pf("\n");
    for(int i=1;i<=42;i++)
        pf(" ");
    pf("Total      ");
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    string s;
    reset();
    while(get_stl(s))
    {
        if(s.empty())   break;
        string x,y,r,c;
        int u,v,i;

        for(i=0;;i++)
        {
            if(s[i]==',')
            {
                if(ID[x]==0)
                    ID[x] = ID.size();
                u = ID[x];
                city[u] = x;
                break;
            }
            x+=s[i];
        }

        while(i++)
        {
            if(s[i]==',')
            {
                if(ID[y]==0)
                    ID[y] = ID.size();
                v = ID[y];
                city[v] = y;
                break;
            }
            y+=s[i];
        }

        while(i++)
        {
            if(s[i]==',')
                break;
            r+=s[i];
        }

        i++;

        while(s[i])
        {
            c+=s[i];
            i++;
        }

        int cost = atoi(c.c_str());

        if(grid[u][v]>cost)
        {
            grid[u][v] = cost;
            grid[v][u] = cost;

            road[pii(u,v)] = r;
            road[pii(v,u)] = r;
        }
    }

    floyedWarshall(ID.size());

    int kase = 0;

    while(get_stl(s))
    {
        kase++;

        if(kase)
            pf("\n\n");

        string x,y;
        int i;

        for(i=0;;i++)
        {
            if(s[i]==',')   break;
            x+=s[i];
        }

        for(i++;s[i];i++)
            y+=s[i];

        int s = ID[x];
        int d = ID[y];

        find_path(s,d);

        header();

        for(int i=0,j=1;j<loc.size();i++,j++)
            printf("%-20s %-20s %-10s %5d\n",city[loc[i]].c_str(),city[loc[j]].c_str(),road[pii(loc[i],loc[j])].c_str(),grid[loc[i]][loc[j]]);

        footer();

        pf("%5d\n",grid[s][d]);

        loc.clear();
    }
    return 0;
}
