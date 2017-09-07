#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n<0&&n%2==0)
            pf("Underflow!\n");

        else if(n<0&&n%2!=0)
            pf("Overflow!\n");
        else if(n==0||n<=7)
            pf("Underflow!\n");
        else if(n>=8&&n<=13)
        {
            ull ans = 1;
            for(int i=1;i<=n;i++)
                ans*=i;
            puf(ans);
        }
        else if(n>13)
            pf("Overflow!\n");
    }

    return 0;
}
