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

    int number,mod,count;
    string ans;
    while(1)
    {
        sf("%d", &number);

        if(number==0)
            break;

        count=0;
        while(number)
        {
            mod=number%2;
            if(mod)
                count++;
            ans.push_back(mod+48);
            number/=2;
        }

        reverse(ans.begin(),ans.end());

        pf("The parity of %s is %d (mod 2).\n",ans.c_str(),count);

        ans.clear();
    }

    return 0;
}
