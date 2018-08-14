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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    vector<string>v1,v2;

    char a[500],b[500];
    int DP[102][102];

    while(scanf("%s",a)==1)
    {
        if(a[0]=='#')
        {
            while(scanf("%s",b)==1)
            {
                if(b[0]=='#')   break;
                v2.push_back(b);
            }
            mem(DP,0);
            int len = 0;
            for(int i=v1.size()-1;i>=0;i--)
            {
                for(int j=v2.size()-1;j>=0;j--)
                {
                    if(v1[i]==v2[j])    DP[i][j] = 1 + DP[i+1][j+1];
                    else                DP[i][j] = max(DP[i+1][j],DP[i][j+1]);
                    len = max(len,DP[i][j]);
                }
            }
            for(int i=0;i<v1.size();i++)
            {
                for(int j=0;j<v2.size();j++)
                {
                    if(v1[i]==v2[j] && len == DP[i][j])
                    {
                        len--;
                        printf("%s",v1[i].c_str());
                        (len) ? printf(" ") : printf("\n");
                        break;
                    }
                }
            }
            v1.clear();
            v2.clear();
        }
        v1.push_back(a);
    }
    return 0;
}
