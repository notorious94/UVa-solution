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

    int r,a,b;

    int square[100001];
    memset(square, 0, sizeof(square));

    for(int i=1;i<=100000;i++)
    {
        r=sqrt(i);
        if(r*r==i)
            square[i]=1;
    }

    for(int i=1;i<=100000;i++)
        square[i]+=square[i-1];

    while(1)
    {
        sf("%d%d",&a,&b);
        if(a==0&&b==0)
            break;
        pf("%d\n",square[b]-square[a-1]);
    }
    return 0;
}
