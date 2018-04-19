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

int freq[31];
string seperator = "!.,?";

void count_freq(string s)
{
    int len = 0;
    for(int i=0;s[i];i++)
    {
        if(binary_search(all(seperator),s[i]))
        {
            freq[len]++;
            len = 0;
            continue;
        }
        if(s[i]=='\''||s[i]=='-')
            continue;
        else
            len++;
    }
    freq[len]++;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sort(all(seperator));

    char s[50],hyphen = '-';
    string a="",b="";
    mem(freq,0);

    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='#')
        {
            for(int i=1;i<=30;i++)
                if(freq[i])
                    printf("%d %d\n",i,freq[i]);
            puts("");
            mem(freq,0);
            continue;
        }
        if(s[strlen(s)-1]==hyphen)
        {
            a = s;
            continue;
        }
        else
        {
            b = s;
            if(a=="")
                count_freq(b);
            else
            {
                count_freq(a+b);
                a = "";
            }
        }
    }
    return 0;
}
