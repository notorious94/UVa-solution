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

    int t,c;
    int result[5];

    sif(t);

    while(t--)
    {
        c=0;
        for(int i=0;i<5;i++)
        {
            sif(result[i]);
            if(i>0)
                if(result[i-1]+1==result[i])
                    c++;
        }
        (c==4) ? pf("Y\n") : pf("N\n");
    }

    return 0;
}
