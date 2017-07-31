#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define pi acos(-1.0)
typedef long long ll;
typedef unsigned long long ull;

int factorialDigit ( int n )
{
    if(n==0||n==1)
        return 1;
    return floor(((n+0.5)*log(n)-n+0.5*log(2*pi))/log(10))+1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    sif(t);
    while(t--)
    {
        sif(n);
        pf("%d\n",factorialDigit(n));
    }
    return 0;
}
