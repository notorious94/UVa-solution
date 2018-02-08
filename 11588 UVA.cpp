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
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int freq[27];
    int r,c,m,n,test;
    char s[500];
    sf("%d",&test);

    for(int kase = 1;kase<=test;kase++)
    {
        int max_freq = 0;
        mem(freq,0);

        scanf("%d%d%d%d",&r,&c,&m,&n);

        for(int i=0;i<r;i++)
        {
            sf("%s",s);
            for(int j=0;j<c;j++)
            {
                ++freq[s[j]-'A'];
                max_freq = max(max_freq,freq[s[j]-'A']);
            }
        }

        int mb = 0;

        for(int i=0;i<27;i++)
        {
            if(freq[i]==max_freq)
                mb+=(m*freq[i]);
            else
                mb +=  (n*freq[i]);
        }

        pf("Case %d: %d\n",kase,mb);
    }

    return 0;
}
