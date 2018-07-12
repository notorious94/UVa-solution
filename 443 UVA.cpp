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

vector<int>ara;
int c[400];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    set<ll>r;
    set<ll>::iterator i,j;
    vector<ll>s;
    r.insert(1);
    ll p = 2,m;
    while(p<=2000000000)
        r.insert(p),p*=2;
    p = 3;
    while(p<=2000000000)
        r.insert(p),p*=3;
    p = 5;
    while(p<=2000000000)
        r.insert(p),p*=5;
    p = 7;
    while(p<=2000000000)
        r.insert(p),p*=7;;
    p = 2000000000;
    for(i=r.begin();i!=r.end();i++)
    {
        j = i;
        j++;
        for(;j!=r.end();j++)
        {
            ll a = *i;
            ll b = *j;
            m = a*b;
            if(m<=p&&m>1)   r.insert(m);
            else break;
        }
    }

    for(i = r.begin();i!=r.end();i++)
        s.push_back(*i);
    //cout<<s.size()<<endl;
    int n;
    while(scanf("%d",&n))
    {
        if(!n)  break;
        printf("The %d",n);
        if(n%10==1 && (n/10)%10!=1) printf("st ");
        else if(n%10==2 && (n/10)%10!=1) printf("nd ");
        else if(n%10==3 && (n/10)%10!=1) printf("rd ");
        else printf("th ");
        printf("humble number is %lld.\n",s[n-1]);
    }
    return 0;
}
