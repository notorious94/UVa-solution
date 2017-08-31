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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ull table[50001];
    table[1] = 1;

    for(ull i=2;i<=50000;i++)
        table[i] = i*i*i+table[i-1];

    ull n;

    while(sf("%llu",&n)!=EOF)
        puf(table[n]);

    return 0;
}
