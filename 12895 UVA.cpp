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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ull t,p,sum;
    string n;
    char ans[50];

    sf("%llu",&t);

    while(t--)
    {
        cin>>n;
        p = n.size();
        sum=0;
        for(int i=0;n[i]!=0;i++)
            sum+=ceil(pow((n[i]-48),p));

        sprintf(ans,"%llu",sum);

        (n==ans) ? pf("Armstrong\n") : pf("Not Armstrong\n");
    }

    return 0;
}
