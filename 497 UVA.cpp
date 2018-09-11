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
#define sif(a) scanf("%d",&a)
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

/*
int lp[32001];
vector<int>prime;

void sieve(int limit = 32001)
{
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
*/
vector<int>data,dp,track;

void print(int n)
{
    if(n==track[n])
    {
        printf("%d\n",data[n]);
        return;
    }
    print(track[n]);
    printf ("%d\n",data[n]);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    char num[100];

    scanf("%d\n\n",&t);

    while(t--)
    {
        data.clear();
        dp.clear();
        track.clear();

        int n = 0,LIS = 1,start = 0;

        while(gets(num))
        {
            if(!num[0])   break;
            data.push_back(atoi(num));
            dp.push_back(1);
            track.push_back(n++);
        }

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(data[i]<data[j]&&dp[j]<=dp[i]+1)
                {
                    dp[j] = dp[i]+1;
                    track[j] = i;
                    if(LIS<=dp[j])
                    {
                        LIS = dp[j];
                        start = j;
                    }
                }
            }
        }

        printf("Max hits: %d\n",LIS);
        print(start);
        if(t)   puts("");

    }
    return 0;
}
