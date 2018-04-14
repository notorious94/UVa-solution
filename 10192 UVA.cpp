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


int DP[105][105];
char a[105],b[105];

int LCS(int i=0,int j=0)
{
    if(!a[i]||!b[j])    return 0;
    if(DP[i][j]!=-1)    return DP[i][j];
    int ans = 0;
    if(a[i]==b[j])      ans = 1 + LCS(i+1,j+1);
    else                ans = max(LCS(i+1,j),LCS(i,j+1));
    return DP[i][j] = ans;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int kase = 0;
    while(gets(a))
    {
        if(a[0]=='#')   break;
        mem(DP,-1);
        gets(b);
        printf("Case #%d: you can visit at most %d cities.\n",++kase,LCS());
    }

    return 0;
}
