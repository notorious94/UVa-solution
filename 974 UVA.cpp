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

    int kaprekar[] ={9,45,55,99,297,703,999,2223,2728,4879,4950,5050,5292,7272,7777,9999,17344,22222,38962};
    int test,a,b;
    bool p;

    sif(test);

    for(int c=1;c<=test;c++)
    {
        p=false;
        sf("%d%d", &a,&b);
        pf("case #%d\n", c);

        for(int i=0;i<19;i++)
        {
            if(kaprekar[i]>=a&&kaprekar[i]<=b)
            {
                p=true;
                pf("%d\n",kaprekar[i]);
            }
        }

        if(p==false)
            pf("no kaprekar numbers\n");
        if(c!=test)
            cout<<endl;
    }
    return 0;
}
