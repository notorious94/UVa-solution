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

    int non_z[10001];
    string fact;
    fact.push_back('1');
    non_z[0]=1;
    non_z[1]=1;

    for(int i=2,c=0;i<=10000;c=0,i++)
    {
        bool got_digit = true;
        for(int j=0;fact[j]!=0;j++)
        {
            c+=(fact[j]-48)*i;
            (c>9) ? fact[j]=((c%10)+48) : fact[j]=(c+48);

            if(got_digit&&fact[j]!=48)
            {
                non_z[i]=fact[j]-48;
                got_digit=false;
            }

            c/=10;
        }
        while(c)
        {
            (c>9) ? fact.push_back((c%10)+48) : fact.push_back(c+48);
            c/=10;
        }
    }

    int n;
    while(sif(n)!=EOF)
        pf("%5d -> %d\n",n,non_z[n]);

    return 0;
}
