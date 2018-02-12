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

    int t,px,py;
    char c,m;
    string s[5];

    scanf("%d",&t);

    for(int k=1;k<=t;k++)
    {
        for(int i=0;i<5;i++)
        {
            s[i].clear();
            for(int j=0;j<5;j++)
            {
                scanf(" %c",&c);
                if(c=='>'||c=='<')
                {
                    px = i;
                    py = j;
                    m = c;
                }
                s[i]+=c;
            }
        }

        pf("Case %d: ",k);

        if(m=='<')
        {
            bool noBall = false;
            while(py<5)
            {
                if(s[px][++py]=='|')
                {
                    noBall = true;
                    break;
                }
            }
            if(noBall)
                pf("No Ball\n");
            else
                pf("Thik Ball\n");
        }

        else
        {
            bool noBall = false;
            while(py>=0)
            {
                if(s[px][--py]=='|')
                {
                    noBall = true;
                    break;
                }
            }
            if(noBall)
                pf("No Ball\n");
            else
                pf("Thik Ball\n");
        }
    }
    return 0;
}
