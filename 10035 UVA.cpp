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

int sum(string a, string b)
{
    int x,y,count=0;

    for(int i=a.size()-1, j=b.size()-1, carry=0;i>=0||carry||j>=0;i--,j--)
    {
        (i<0) ? x = 48 : x = a[i];
        (j<0) ? y = 48 : y = b[j];
        carry = x + y + carry - 96;
        carry /=10;
        if(carry)
            count++;
    }
    return count;
}


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a,b;
    int n;
    while(cin>>a>>b)
    {
        if(a=="0"&&b=="0")
            break;
        n=sum(a,b);
        if(n==0)
            pf("No carry operation.\n");
        else if(n>1)
            pf("%d carry operations.\n",n);
        else
            pf("1 carry operation.\n");
    }
    return 0;
}
