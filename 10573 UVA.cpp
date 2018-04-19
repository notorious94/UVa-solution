// TF t is given then r1 = r2 = t/4
// else as usual
// R = r1 + r2
// There will be no Impossible 

#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi 2*acos(0)
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
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double r1,r2,R;
    int test;
    char s[10000];
    scanf("%d\n",&test);
    while(test--)
    {
        gets(s);
        int a=0,b=0;
        sscanf(s,"%d %d",&a,&b);
        if(a!=0&&b==0)
        {
            r1 = (double)a/4.0;
            r2 = (double)a/4.0;
        }
        else if(a==0&&b!=0)
        {
            r1 = (double)b/4.0;
            r2 = (double)b/4.0;
        }
        else
        {
            r1 = a;
            r2 = b;
        }
        R = (r1+r2);
        double area = pi*R*R -(pi*(r1*r1)+pi*(r2*r2));
        printf("%0.4lf\n",area);
    }

    return 0;
}
