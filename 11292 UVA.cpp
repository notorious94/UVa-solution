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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n,a;
    vector<int>head,height;
    while(scanf("%d%d",&n,&m))
    {
        if(!n&&!m)  break;
        head.clear();
        height.clear();

        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            head.push_back(a);
        }

        for(int i=0;i<m;i++)
        {
            scanf("%d",&a);
            height.push_back(a);
        }

        if(n>m)
        {
            puts("Loowater is doomed!");
            continue;
        }

        bool doom = false;
        ll sum = 0,start = 0;

        sort(all(head));
        sort(all(height));

        for(int i=0;i<n;i++)
        {
            bool found = false;
            for(int j=start;j<m;j++)
            {
                if(head[i]<=height[j]) /// DRAGON'S HEAD DIAMETER IS LESS THEN OR EQUAL TO SOILDERS HEIGHT
                {
                    sum+=height[j];
                    found = true;
                    start = j+1;
                    break;
                }
            }
            if(!found)
            {
                doom = true;
                break;
            }
        }
        
        if(doom)
            puts("Loowater is doomed!");
        else
            printf("%lld\n",sum);
    }
    return 0;
}
