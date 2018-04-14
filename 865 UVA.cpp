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

int _replace[265];
void reset()
{
    for(int i=0;i<265;i++)
        _replace[i] = i;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int test;
    char plaintext[500],substitution[500];
    char line[500];
    scanf("%d\n\n",&test);
    while(test--)
    {
        gets(plaintext);
        gets(substitution);

        reset();
        for(int i=0;plaintext[i];i++)
            _replace[plaintext[i]] = substitution[i];

        printf("%s\n%s\n",substitution,plaintext);

        while(gets(line))
        {
            if(!line[0])    break;
            for(int i=0;line[i];i++)
            {
                line[i] =_replace[line[i]];
                printf("%c",line[i]);
            }
            puts("");
        }
        if(test)    puts("");
    }
    return 0;
}
