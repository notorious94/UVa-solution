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

int div_one(int n)
{
    int r=sqrt(n);
    int count=0;
    for(ull i=1;i<=r;i++)
        if(n%i==0)
            count+=2;

    if(r*r==n)
        return count-1;
    else
        return count;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l,u,t,max,number,div;
    sif(t);
    while(t--)
    {
        sf("%d%d",&l,&u);

        pf("Between %d and %d, ",l,u);

        max=-1;

        for(l;l<=u;l++)
        {
            div = div_one(l);
            if(max<div)
            {
                number=l;
                max=div;
            }
        }
        pf("%d has a maximum of %d divisors.\n",number,max);
    }
    return 0;
}
