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

    char skew[120];

    while(gets(skew))
    {
        if(skew[0]==48)
            break;

        int power=strlen(skew);
        int decimal=0;

        for(int i=0;skew[i]!=0;i++)
        {
            decimal+=(skew[i]-48)*(ceil(pow(2,power))-1);
            power--;
        }

        pif(decimal);

    }
    return 0;
}
