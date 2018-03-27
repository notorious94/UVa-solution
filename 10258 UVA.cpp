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

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

class leaderboard
{
public:

    int team,ac,penalty;

    leaderboard(int t,int a,int p)
    {
        team = t;
        ac = a;
        penalty = p;
    }

    void print()
    {
        printf("%d %d %d\n",team,ac,penalty);
    }

    bool operator < (const leaderboard &p) const
    {
        if(ac!=p.ac)    return ac > p.ac;
        if(penalty!=p.penalty)    return penalty < p.penalty;
        return team < p.team;
    }

};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int stat[101][11][3];
    char v[2],s[500];
    int T,pn,t,test;

    scanf("%d\n\n",&test);

    while(test--)
    {
        mem(stat,0);

        set<int>team;
        vector<leaderboard>board;
        set<int> :: iterator it;

        while(gets(s))
        {
            if(!s[0])   break;
            sscanf(s,"%d%d%d%s",&T,&pn,&t,v);

            team.insert(T);

            if(!stat[T][pn][1] && v[0] == 'C') // AC
            {
                stat[T][pn][1] = 1; // Flag
                stat[T][pn][2] = t; // Penalty Time
            }

            else if(!stat[T][pn][1] && v[0] == 'I') // WA
                stat[T][pn][0]++; // WA
        }

        for(it = team.begin();it!=team.end();it++)
        {
            int penalty = 0,solve=0;
            T = *it;
            for(int j=1;j<=10;j++)
            {
                if(stat[T][j][1])
                {
                    solve++;
                    penalty+=(stat[T][j][2] + 20*stat[T][j][0]);
                }
            }
            board.push_back(leaderboard(T,solve,penalty));
        }

        sort(all(board));

        for(int i=0;i<board.size();i++)
            board[i].print();

        if(test)    puts("");

    }

    return 0;
}
