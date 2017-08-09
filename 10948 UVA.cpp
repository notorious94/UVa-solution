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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool>prime(1000001,true);

    int size = 1000001, r=sqrt(size);
    prime[0]=false;
    prime[1]=false;

    for(int i=2;i<=r;i++)
        if(prime[i])
            for(int j=2;i*j<size;j++)
                prime[i*j]=false;
    int n;

    while(1)
    {
        sif(n);
        if(n==0)
            break;
        int a=0,b=0;
        for(int i=n-1;i>=0;i--)
            if(prime[n-i]&&prime[i])
            {
                a=n-i;
                b=i;
                break;
            }

        pf("%d:\n",n);
        if(a==0&&b==0)
            pf("NO WAY!\n");
        else
            pf("%d+%d\n",a,b);

    }
    return 0;
}
