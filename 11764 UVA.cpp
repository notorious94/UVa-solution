#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 600
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

    vector<int>jump;
    int t,n,v,max,min;

    sif(t);
    for(int c=1;c<=t;c++)
    {
        pf("Case %d: ",c);
        sif(n);

        max=0,min=0;

        for(int i=0;i<n;i++)
        {
            sif(v);
            jump.push_back(v);

            if(i!=0)
                if(jump[i]>jump[i-1])
                    max++;
                else if(jump[i]<jump[i-1])
                    min++;
        }
        pf("%d %d\n",max,min);
        jump.clear();
    }

    return 0;
}
