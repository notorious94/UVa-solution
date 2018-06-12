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

int p[1000001];
vector<int>prime;
vector<int>::iterator it;

void sieve()
{
    for(int i=2;i<=1000000;i++)
    {
        if(!p[i])
        {
            p[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=1000000&&prime[j]<=i;j++)
            p[i*prime[j]] = prime[j];
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int l,u,li,test;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d%d",&l,&u);
        it = lower_bound(all(prime),l);
        li = it - prime.begin();

        if(li==prime.size())
        {
            pf("No jumping champion\n");
            continue;
        }

        map<int,int>freq_count;
        vector<int>ans;
        int max_freq = 0;

        for(int i = li, j=li+1;j<prime.size()&& prime[j]<=u;i++,j++)
        {
            int diff = prime[j] - prime[i];
            int f = ++freq_count[diff];
            if(f>max_freq)
            {
                max_freq = f;
                ans.clear();
                ans.push_back(diff);
            }
            else if(f==max_freq)
                ans.push_back(diff);
        }

        //cout<<ans.size()<<" "<<max_freq<<" "<<ans[0]<<endl;
        if(max_freq==0||ans.size()>1)
            pf("No jumping champion\n");
        else    printf("The jumping champion is %d\n",ans[0]);
    }
    return 0;
}
