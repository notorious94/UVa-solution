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

int digitsum[1001];

void factorial()
{
    string result;
    digitsum[0]=1;
    result.push_back('1');

    for(int i=1;i<=1000;i++)
    {
        int carry = 0;
        int sum=0;
        int mod;

        for(int j=0;result[j]!=0;j++)
        {
            carry += (i * (result[j]-48));
            mod = carry%10;
            sum+=mod;
            result[j]=(mod+48);
            carry/=10;
        }

        while(carry)
        {
            mod = carry%10;
            sum+=mod;
            result.push_back(mod+48);
            carry/=10;
        }

        digitsum[i]=sum;
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial();

    int n;

    while(sif(n)!=EOF)
        pif(digitsum[n]);

    return 0;
}
