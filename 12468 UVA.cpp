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

int counter(int a, int b)
{
    int count=0;
    for(;;a++)
    {
        if(a>99)
            a=0;
        ++count;
        if(a==b)
            break;
    }
    return --count;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c1,c2;

    while(1)
    {
        sf("%d%d",&a,&b);
        if(a==-1&&b==-1)
            break;
        c1=counter(a,b);
        c2=counter(b,a);
        pif(min(c1,c2));
    }
    return 0;
}
