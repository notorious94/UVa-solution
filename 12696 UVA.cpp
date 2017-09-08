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

    double length,width,depth,weight;
    int test,allowed=0;

    sif(test);

    while(test--)
    {
        sf("%lf%lf%lf%lf",&length,&width,&depth,&weight);

        if(length<=56.00&&width<=45.00&&depth<=25.00&&weight<=7.00)
        {
            allowed++;
            pf("1\n");
        }

        else if(length+width+depth<=125.00&&weight<=7.00)
        {
            allowed++;
            pf("1\n");
        }

        else
            pf("0\n");
    }

    pif(allowed);

    return 0;
}
