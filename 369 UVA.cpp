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

typedef long long ll;
typedef unsigned long long ull;

ull dp[101][101];
bool visit[101][101];

ull combination(ull n, ull r)
{
    if(r==1||r+1==n)
        return n;

    else if(n==r)
        return 1;

    if(visit[n][r])
        return dp[n][r];

    visit[n][r]=true;
    return dp[n][r] = combination(n-1,r) + combination(n-1,r-1);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull n,r;

    for(int i=5;i<=100;i++)
        for(int j=1;j<=i;j++)
            combination(i, j);

    while(sf("%llu%llu", &n, &r))
    {
        if(!n&&!r)
            break;

        pf("%llu things taken %llu at a time is %llu exactly.\n",n,r,combination(n,r));
    }

    return 0;
}
