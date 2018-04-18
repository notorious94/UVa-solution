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

vector<string>words;

string message()
{
    string msg;
    for(int i=0,len=1,jump=1;i<words.size();i++)
        if(words[i].size()>=len)
        {
            msg+=words[i][len-1];
            len=++jump;
        }
    return msg;
}

char s[1000000];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test,kase=0;
    scanf("%d\n\n",&test);
    while(test--)
    {
        printf("Case #%d:\n",++kase);
        while(gets(s))
        {
            if(!s[0])   break;
            words.clear();
            char *t;
            t = strtok(s," ");
            while(t!=NULL)
            {
                words.push_back(t);
                t = strtok(NULL," ");
            }
            pf("%s\n",message().c_str());
        }
        if(test)    puts("");
    }

    return 0;
}
