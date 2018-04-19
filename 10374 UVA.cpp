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
#define pdd pair<double, double>
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

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

map<string,int> person;
map<string,int> ::iterator it;

string party_names[21];
int party_votes[21];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    int n,m;
    char name[100],party[100];

    scanf("%d\n\n",&test);

    while(test--)
    {
        scanf("%d\n",&n);
        person.clear();

        for(int i=1;i<=n;i++)
        {
            gets(name);
            gets(party);
            person[name] = i;
            party_names[i] = party;
            party_votes[i] = 0;
        }

        scanf("%d\n",&m);
        int vote,max_vote = 0;

        while(m--)
        {
            gets(name);
            it = person.find(name);
            if(it!=person.end())
            {
                vote = ++party_votes[it->second];
                max_vote = max(max_vote,vote);
            }
        }

        int candidate = 0;
        int winner_index;

        for(int i=1;i<=n;i++)
            if(party_votes[i]==max_vote)
            {
                candidate++;
                winner_index = i;
            }
        getc(stdin);

        if(candidate==1)
            printf("%s\n",party_names[winner_index].c_str());
        else
            puts("tie");
        if(test)    puts("");
    }
    return 0;
}
