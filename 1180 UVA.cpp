#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define sif(n) scanf("%d",&n)
#define lif(n) scanf("%lld",&n)
#define MAX 1000005
#define MOD 100000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define p_b push_back
#define ff first
#define ss second
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >

typedef long long ll;
typedef unsigned long long ull;

enum COLOR { W = 0, G = 1, B = 2};

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


int lp[363];
vector<int>prime;

void sieve(int limit = 363)
{
    lp[0] = lp[1] = -1;
    for(int i=2;i<limit;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&i*prime[j]<limit;j++)
            lp[i*prime[j]]=i;
    }
}

bool isPrime(ll p)
{
    if(p<363)   return (lp[p]==p);
    int r = sqrt(p);
    for(int i=0;i<prime.size()&&prime[i]<=r;i++)
        if(p%prime[i]==0)   return false;
    return true;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    vector<ll>ans;
    for(int p=1;p<=17;p++)
    {
        ll P = pow(2,p)-1;
        if(isPrime(p)&&isPrime(P))
            ans.push_back(p);
    }
    sort(all(ans));
    int test;
    string s;
    cin>>test;
    cin>>s;
    s+=",";
    string temp;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==',')
        {
            if(binary_search(all(ans),atoi(temp.c_str())))
                    cout<<"Yes"<<endl;
            else    cout<<"No"<<endl;
            temp.clear();
        }
        else
            temp+=s[i];
    }
    return 0;
}
