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

ll bigMod(ll n, ll p, ll m)
{
    if(!p)  return 1%m;
    if(p&1) return ( bigMod(n,p-1,m)%m * n%m ) % m;
    else
    {
        ll a = bigMod(n,p/2,m)%m;
        return (a*a)%m;
    }
}

int toDecimal(char m[],int base)
{
    int decimal = 0;
    for(int i=0,p=strlen(m)-1;m[i];i++,p--)
        if(m[i]!='0')
        {
            int b = ceil(pow(base,p));
            int a = m[i]-'0';
            decimal+=(a*b);
        }
    return decimal;
}

ll remainder(char a[],int base,int mod)
{
    ll r = 0;
    ll p = strlen(a)-1;
    for(int i=0;a[i];i++,p--)
    {
        r += ((a[i]-'0')%mod * bigMod(base,p,mod));
        r %= mod;
    }
    return r;
}

string convertTo(int r,int base)
{
    if(!r)
        return "0";
    string number;
    while(r)
    {
        int m = r%base;
        number += (m+'0');
        r/=base;
    }
    reverse(all(number));
    return number;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char n[10005],m[50];
    int base;
    while(scanf("%d",&base))
    {
        if(base==0) break;
        scanf("%s%s",n,m);
        int mod = (base==10) ? atoi(m) : toDecimal(m,base);
        ll r = remainder(n,base,mod);
        if(base==10)
            printf("%lld\n",r);
        else
        {
            string result = convertTo(r,base);
            printf("%s\n",result.c_str());
        }
    }

    return 0;
}
