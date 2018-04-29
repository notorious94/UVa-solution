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

string grid[301][301];
int LCS[301][301];

void common_substring(char s1[],char s2[])
{
    int max_len = 0;
    set<string>result;
    for(int i=0;s1[i];i++)
    {
        for(int j=0;s2[j];j++)
        {
            if(s1[i]==s2[j])
            {
                int len;
                LCS [i][j] = 1;
                grid[i][j].clear();
                grid[i][j].push_back(s1[i]);

                if(i-1>=0&&j-1>=0&&LCS[i-1][j-1])
                {
                    LCS[i][j]+=LCS[i-1][j-1];
                    grid[i][j] = grid[i-1][j-1] + grid[i][j];
                }

                if(max_len < LCS[i][j])
                {
                    max_len = LCS[i][j];
                    result.clear();
                    result.insert(grid[i][j]);
                }
                else if(max_len==LCS[i][j])
                    result.insert(grid[i][j]);

            }
            else
            {
                grid[i][j] = "#";
                LCS[i][j] = 0;
            }
        }
    }
    if(max_len==0)
    {
        printf("No common sequence.\n");
        return;
    }
    set<string>::iterator it;
    for(it=result.begin();it!=result.end();it++)
        cout<<*it<<endl;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    char s1[500],s2[500];
    int k = 0;
    while(scanf("%s",s1)==1)
    {
        if(++k>1)   puts("");
        scanf("%s",s2);
        common_substring(s1,s2);
    }
    return 0;
}
