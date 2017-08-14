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

    int N,K;
    double M,cost;
    char s[11000];
    map<char, double>paid_char;

    sif(N);
    while(N--)
    {
        for(int i=1;i<=256;i++)
            paid_char[i]=0;

        sif(K);
        while(K--)
        {
            sf("%s%lf",s,&M);
            paid_char[s[0]]=M;
        }

        sf("%d\n",&K);
        cost=0;

        while(K--)
        {
            gets(s);
            for(int i=0;s[i]!=0;i++)
                cost+=paid_char[s[i]];
        }

        pf("%0.2lf$\n",cost/100.00);
    }
    return 0;
}
