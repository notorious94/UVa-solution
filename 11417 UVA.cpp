#include<bits/stdc++.h>
using namespace std;

///Template Starts Here
#define pf printf
#define sf scanf
#define MAX 600

typedef long long ll;
typedef unsigned long long ull;

int gcd(int a, int b)
{
    int temp;
    while(b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(1)
    {
        sf("%d",&n);
        if(n==0)
            break;
        int g=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                g+=gcd(i,j);

        printf("%d\n",g); ///Accessing DATA
    }

    return 0;
}
