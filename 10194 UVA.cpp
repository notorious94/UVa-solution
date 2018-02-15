#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 800000
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
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

/// Template Ends Here

class Soccer
{
public:
    string name;
    int point,games,wins,tie,loss,diff,scored,against;

    Soccer(string n,int p, int g, int w,int t, int l, int s,int a) /// Constructor
    {
        name = n;
        tie = t;
        point = p;
        games = g;
        wins = w;
        loss = l;
        scored = s;
        against = a;
        diff = (s-a);
    }

    void print(int s){
        printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",s,name.c_str(),point,games,wins,tie,loss,diff,scored,against);
    }

    bool operator < (const Soccer &p) const{ /// There maybe a BUG in it
        if(point != p.point)    return point > p.point;
        if(wins != p.wins)      return wins  > p.wins;
        if(diff != p.diff)      return diff  > p.diff;
        if(scored != p.scored)  return scored > p.scored;
        if(games != p.games)    return games < p.games;
        return strcasecmp(name.c_str(), p.name.c_str()) < 0;
    }

};

int stat[31][8]; // This is for calculating scores

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    vector<Soccer>leaderBoard;
    string t_name,name;
    map<string,int>name_list;
    map<int,string>locateID;
    char description[MAX];

    int test,t,g;

    scanf("%d\n",&test);

    while(test--)
    {
        mem(stat,0);
        name_list.clear();
        locateID.clear();
        leaderBoard.clear();

        get_stl(t_name);
        scanf("%d\n",&t);

        for(int i=1;i<=t;i++)
        {
            get_stl(name);
            name_list[name] = i;
            locateID[i] = name;
        }

        scanf("%d\n",&g);

        while(g--) /// This Section is working Perfectly
        {
            gets(description);
            char name1[500],name2[500];
            int goal_scored,goal_conceived;

            sscanf(description, "%[^#]#%d@%d#%[^\n]", name1,&goal_scored,&goal_conceived,name2);

            int id = name_list[name1];
            int opponent_ID = name_list[name2];

            stat[id][0]++;
            stat[id][1] += goal_scored;
            stat[id][2] += goal_conceived;

            stat[opponent_ID][0]++;
            stat[opponent_ID][1] += goal_conceived;
            stat[opponent_ID][2] += goal_scored;

            if(goal_scored==goal_conceived)
            {
                stat[id][3]++;
                stat[id][4]++;
                stat[opponent_ID][3]++;
                stat[opponent_ID][4]++;
            }

            else if(goal_scored>goal_conceived)
            {
                stat[id][3]+=3; // Point +3
                stat[id][5]++; // Win +1
                stat[opponent_ID][6]++; // Opponent Loss +1
            }

            else if(goal_scored<goal_conceived)
            {
                stat[opponent_ID][3]+=3;
                stat[opponent_ID][5]++;
                stat[id][6]++;
            }

        }

        for(int i=1;i<=t;i++)
            //Soccer(string n,int p, int g, int w,int t, int l, int s,int a)
            leaderBoard.push_back(Soccer(locateID[i],stat[i][3],stat[i][0],stat[i][5],stat[i][4],stat[i][6],stat[i][1],stat[i][2]));

        sort(leaderBoard.begin(),leaderBoard.end());

        pf("%s\n",t_name.c_str());

        for(int i=0;i<leaderBoard.size();i++)
            leaderBoard[i].print(i+1);

        if(test)    puts("");
    }
    return 0;
}
