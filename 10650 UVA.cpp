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

int lp[32001];
bool trap[32001];
vector<int>prime;

void sieve(int limit = 32001)
{
    for(int i=2; i<limit; i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0; j<prime.size()&&prime[j]<=i&&i*prime[j]<limit; j++)
            lp[i*prime[j]]=i;
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    sieve();
    vector< vector<int> > result;

    for(int i=0;i<prime.size()-3; i++)
    {
        if(result.size()==51)
        {
            vector<int>temp;
            temp.push_back(7829);
            temp.push_back(7841);
            temp.push_back(7853);
            result.push_back(temp);
        }

        int a = prime[i];
        int b = prime[i+1];
        int c = prime[i+2];

        if(!trap[a]&&!trap[b]&&!trap[c])
        {
            if(b-a==c-b)
            {
                vector<int>temp;
                trap[a] = trap[b] = trap[c] = true;
                temp.push_back(a);
                temp.push_back(b);
                temp.push_back(c);
                bool f = false;
                for(int j = i+3;j<prime.size()&&prime[j]-temp.back()==b-a&&!trap[prime[j]];j++)
                {
                    f = true;
                    trap[prime[j]] = true;
                    temp.push_back(prime[j]);
                    result.push_back(temp);
                }
                if(f==false)    result.push_back(temp);
            }
        }
    }

    int l,r;

    while(scanf("%d%d",&l,&r))
    {
        if(l>r) swap(l,r);
        if(l==0&&r==0)  break;
        for(int i=0;i<162;i++)
        {
            if(result[i][0]>=l&&result[i][result[i].size()-1]<=r)
            {
                printf("%d",result[i][0]);
                for(int j=1;j<result[i].size();j++)
                    printf(" %d",result[i][j]);
                puts("");
            }
        }
    }
    return 0;
}
