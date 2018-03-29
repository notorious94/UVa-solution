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
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

class team
{
public:
    string name;
    int p,gp,sg,cg,gd;
    team(string n,int P,int GP,int SG,int CG)
    {
        name = n;
        p = P;
        gp = GP;
        sg = SG;
        cg = CG;
        gd = sg-cg;
    }
    bool operator < (team &n)
    {
        if(p!=n.p)      return p  > n.p;
        if(gd!=n.gd)    return gd > n.gd;
        if(sg!=n.sg)    return sg  > n.sg;
        return strcasecmp(name.c_str(),n.name.c_str()) < 0;
    }
};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    char t1[20],t2[20],hyphen;
    int kase = 0,stat[29][4],t,g,goalDise,goalKhaise;

    while(scanf("%d%d\n",&t,&g))
    {
        if(!t && !g)    break;

        if(++kase>1)    puts("");
        map<string,int>id;
        map<int,string>ID;
        mem(stat,0);
        for(int i=1;i<=t;i++)
        {
            scanf("%s",t1);
            id[t1] = i;
            ID[i] = t1;
        }
        while(g--)
        {
            cin>>t1>>goalDise>>hyphen>>goalKhaise>>t2;

            int a = id[t1];
            int b = id[t2];

            stat[a][1]++; // Game Played
            stat[b][1]++; // Game Played

            stat[a][2]+=goalDise;  // Goal Scored
            stat[b][2]+=goalKhaise;

            stat[a][3] += goalKhaise; // Goal Suffered
            stat[b][3] += goalDise;

            if(goalDise>goalKhaise) // Point Update
                stat[a][0] += 3;

            else if(goalDise<goalKhaise)
                stat[b][0] += 3;

            else
            {
                stat[a][0] ++;
                stat[b][0] ++;
            }
        }

        vector<team>v;

        for(int i=1;i<=t;i++)
            v.push_back(team(ID[i],stat[i][0],stat[i][1],stat[i][2],stat[i][3]));

        sort(all(v));

        for (int i=0;i<v.size();i++)
        {
            if (i == 0 || v[i].p != v[i-1].p || v[i].gd != v[i-1].gd || v[i].sg != v[i-1].sg)
                printf("%2d.",i+1);
            else    printf("   ");
            printf("%16s %3d %3d %3d %3d %3d ", v[i].name.c_str(), v[i].p,v[i].gp,v[i].sg,v[i].cg, v[i].gd);
            if (v[i].gp == 0)
                printf("%6s\n", "N/A");
            else
                printf("%6.2f\n", v[i].p * 100.0 / (3.0 * v[i].gp) + 1e-9);
        }
    }
    return 0;
}
