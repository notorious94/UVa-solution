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

    ull n;
    while(scanf("%llu",&n)!=EOF)
    {
        ull count =0;

        while(n!=1)
        {
            if(n%2!=0)
            {
                n-=1;
                count += n/2;
                n/=2;
                n+=1;
            }
            else
            {
                count+=n/2;
                n/=2;
            }

        }
        printf("%llu\n",count);
    }

    return 0;
}
