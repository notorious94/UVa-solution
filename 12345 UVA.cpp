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
#define all(name) name.begin(),name.end()

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

    int n,m,v,x,y;
    char c[2];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        vector<int>data;
        bool visit[1000000] = {false};

        for(int i=0;i<n;i++)
        {
            scanf("%d",&v);
            data.push_back(v);
        }

        while(m--)
        {
            scanf("%s",c);
            if(c[0]=='Q')
            {
                int count = 0;
                mem(visit,false);
                scanf("%d%d",&x,&y);
                for(int i=x;i<y;i++)
                {
                    if(!visit[data[i]])
                    {
                        count++;
                        visit[data[i]] = true;
                    }
                }
                printf("%d\n",count);
            }
            else
            {
                scanf("%d%d",&x,&y);
                data[x] = y;
            }
        }
    }
    return 0;
}
