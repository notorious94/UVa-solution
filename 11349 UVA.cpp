#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int t,g;
    ll v;
    char s[50];
    vector<ll>data;

    sif(t);

    for(int cas = 1; cas<=t; cas++)
    {
        sf("%s%s%d",s,s,&g);
        data.clear();

        bool neg = false;
        bool sym = true;

        for(int i=0;i<g;i++)
        {
            for(int j=0;j<g;j++)
            {
                sf("%lld",&v);

                data.push_back(v);

                if(v<0)
                    neg = true;
            }
        }

        if(neg)
        {
            pf("Test #%d: Non-symmetric.\n",cas);
            continue;
        }

        for(int i=0,j=data.size()-1;i<data.size()/2;i++,j--)
        {
            if(data[i]!=data[j])
            {
                sym = false;
                break;
            }
        }

        if(sym)
            pf("Test #%d: Symmetric.\n",cas);
        else
            pf("Test #%d: Non-symmetric.\n",cas);

    }

    return 0;
}
