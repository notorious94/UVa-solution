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

    int pair1[5],c;

    while(sf("%d%d%d%d%d",&pair1[0],&pair1[1],&pair1[2],&pair1[3],&pair1[4])!=EOF)
    {
        bool match=true;

        for(int i=0;i<5;i++)
        {
            sf("%d", &c);
            if(c==pair1[i])
                match=false;
        }
        (match) ? pf("Y\n") : pf("N\n");
    }

    return 0;
}
