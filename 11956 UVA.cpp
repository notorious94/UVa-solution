#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 1000000007
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

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};

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

int byte[100];
string pos = "0123456789ABCDEF";
char s[100005];

string hexa(int n)
{
    if(!n)  return "00";
    string result;
    while(n)
    {
        int m = n%16;
        result+=pos[m];
        n/=16;
    }
    reverse(all(result));
    if(result.size()==1)
        result = "0" + result;
    return result;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,kase=0;
    scanf("%d\n",&test);
    while(test--)
    {
        gets(s);
        mem(byte,0);
        int p = 0;
        for(int i=0; s[i]; i++)
        {
            if(s[i]=='.')   continue;
            else if(s[i]=='+')
            {
                byte[p]++;
                if(byte[p]==256)    byte[p]=0;
            }
            else if(s[i]=='-')
            {
                byte[p]--;
                if(byte[p]==-1) byte[p]=255;
            }
            else if(s[i]=='>')
            {
                p++;
                if(p==100)  p = 0;
            }
            else if(s[i]=='<')
            {
                p--;
                if(p==-1)  p = 99;
            }
        }
        printf("Case %d:",++kase);
        for(int i=0; i<100; i++)
            printf(" %s",hexa(byte[i]).c_str());
        puts("");
    }
    return 0;
}
