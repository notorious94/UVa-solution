#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

char digit[MAX];

bool div()
{
    int carry = 0;
    for(int i=0;digit[i]!=0;i++)
    {
        carry = carry*10 +digit[i]-48;
        carry%=17;
    }
    if(carry)
        return false;
    else
        return true;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(sf("%s",digit))
    {
        if(digit[0]=='0')
            break;
        if(div())
            pf("1\n");
        else
            pf("0\n");
    }
    return 0;
}
