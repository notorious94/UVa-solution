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

    int n,p;
    sif(n);

    for(int c=1;c<=n;c++)
    {
        bool possible=true;

        for(int i=1;i<=13;i++)
        {
            sif(p);

            if(!p)
                possible=false;
        }

        if(possible)
            pf("Set #%d: Yes\n",c);
        else
            pf("Set #%d: No\n",c);
    }

    return 0;
}
