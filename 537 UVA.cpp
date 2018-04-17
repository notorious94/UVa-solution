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

double calculate(string s)
{
    int len = s.size();
    double neg = 1.0;
    string num;
    for(int i=2;i<len;i++)
    {
        if(s[i]=='-')
        {
            neg = -1.0;
            continue;
        }
        if(isalpha(s[i]))
        {
            if(s[i]=='m')
                return neg * atof(num.c_str())*(1.0/1000.0);
            else if(s[i]=='k')
                return neg * atof(num.c_str())*(1000.0);
            else if(s[i]=='M')
                return neg * atof(num.c_str())*(1000000.0);
            return 1.0*neg * atof(num.c_str());
        }
        num+=s[i];
    }
    //return 0.0;
}

char s[1000000];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int test,kase = 0;
    scanf("%d\n",&test);

    while(test--)
    {
        gets(s);
        printf("Problem #%d\n",++kase);
        int len=strlen(s);
        double p,u,i;
        bool P,U,I;
        P=U=I=false;
        int c = 0;
        string a,b;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='=')
            {
                string num;
                num+=s[i-1];
                while(i<len)
                {
                    if(isalpha(s[i]))
                    {
                        num+=s[i];
                        break;
                    }
                    num+=s[i];
                    i++;
                }
                if(c==0)    a = num;
                if(c)       b = num;
                if(++c==2)  break;
            }
        }

        if(a[0]=='P')
        {
            if(b[0]=='U')
                printf("I=%0.2lfA\n",calculate(a)/calculate(b));
            else
                printf("U=%0.2lfV\n",calculate(a)/calculate(b));
        }
        else if(a[0]=='U')
        {
            if(b[0]=='P')
                printf("I=%0.2lfA\n",calculate(b)/calculate(a));
            else
                printf("P=%0.2lfW\n",calculate(a)*calculate(b));
        }
        else if(a[0]=='I')
        {
            if(b[0]=='U')
                printf("P=%0.2lfW\n",calculate(b)*calculate(a));
            else
                printf("U=%0.2lfV\n",calculate(b)/calculate(a));
        }
        puts("");
    }

    return 0;
}
