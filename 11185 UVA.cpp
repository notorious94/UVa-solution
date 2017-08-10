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

    ll number,mod;
    string ans;
    while(1)
    {
        sf("%lld", &number);

        if(number<0)
            break;
        if(number==0)
        {
            pf("0\n");
            continue;
        }

        while(number)
        {
            mod=number%3;
            ans.push_back(mod+48);
            number/=3;
        }

        reverse(ans.begin(),ans.end());

        pf("%s\n",ans.c_str());

        ans.clear();
    }

    return 0;
}
