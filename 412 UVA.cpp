#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int data[50];
    int n;

    while(scanf("%d",&n))
    {
        if(!n)  break;

        for(int i=0;i<n;i++)
            scanf("%d",&data[i]);

        double possible_pair = (n*(n-1)/2);
        double pi_pair = 0;

        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(__gcd(data[i],data[j])==1)
                    pi_pair++;

        if(!pi_pair)
            printf("No estimate for this data set.\n");

        else
        {
            double ans = sqrt((6.0*possible_pair)/pi_pair);
            printf("%.6lf\n",ans);
        }

    }
    return 0;
}
