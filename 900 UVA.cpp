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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull brick[51];
    brick[1]=1;
    brick[2]=2;

    for(int i=3;i<51;i++)
        brick[i] = brick[i-1]+brick[i-2];

    int n;

    while(sif(n))
    {
        if(!n)
            break;
        puf(brick[n]);
    }

    return 0;
}
