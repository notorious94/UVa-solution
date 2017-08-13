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

    int n,q,val,loc; /// Required Variables
    vector<int>height; /// Data container

    while(sif(n)!=EOF) /// Total Elements
    {
        for(int i=0;i<n;i++)
        {
            sif(val);
            height.push_back(val);
        }

        sif(q); /// Query

        while(q--)
        {
            sif(val);

            /// Finding Location of the Bigger Element then Item
            loc = upper_bound(height.begin(), height.end(), val) - height.begin();

            /// First Element is larger
            /// So there is no chance of finding any lesser element
            if(loc==0)
                pf("X ");
            else if(height[loc-1]==val)
            {
                int a=loc;
                a--;
                bool p=false;

                while(a>=0)
                {
                    if(height[a]<val)
                    {
                        p=true;
                        pf("%d ", height[a]);
                        break;
                    }
                    a--;
                }
                if(p==false&&a==-1)
                    pf("X ");
            }
            else
                pf("%d ", height[loc-1]);

            /// 1st condition indicating Nth element and the last one is not
            (loc==n) ? pf("X\n") : pf("%d\n", height[loc]);

        }

        height.clear();

    }

    return 0;
}
