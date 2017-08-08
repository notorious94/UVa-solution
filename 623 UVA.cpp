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

    string f,fact[1001];

    f.push_back('1');

    fact[0]=f;
    fact[1]=f;

    for(int i=2,c=0,j=0;i<1001;j=0,c=0,i++)
    {
        for(;f[j]!=0;j++)
        {
            c+=(f[j]-48)*i;
            (c>9) ? f[j]=(c%10)+48 : f[j]=c+48;
            (c>9) ? c/=10 : c=0;
        }

        while(c)
        {
            (c>9) ? f.push_back((c%10)+48) : f.push_back(c+48);
            (c>9) ? c/=10 : c=0;
        }

        fact[i]=f;
        reverse(fact[i].begin(),fact[i].end());
    }

    int n;
    while(sif(n)!=EOF)
    {
        pf("%d!\n",n);
        /*for(int i=fact[n].size()-1;i>=0;i--)
            pf("%c", fact[n][i]);
        pf("\n");*/
        pf("%s\n",fact[n].c_str());
    }
    return 0;
}
