#include<bits/stdc++.h>
using namespace std;

///Template Starts Here
#define pf printf
#define sf scanf
#define MAX 600

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int in,c=0,p;
    vector<int>problem(12,0);
    while(1)
    {
        sf("%d",&in);
        if(in<0)
            break;
        c++;

        for(int i=0;i<12;i++)
            sf("%d",&problem[i]);
        int i=0;
        pf("Case %d:\n", c);
        for(int j=0;j<12;j++)
        {
            sf("%d",&p);
            for(;i<j;i++)
                in += problem[i];
            if(p <= in)
            {
                pf("No problem! :D\n");
                in -=p;
            }
            else
                pf("No problem. :(\n");
        }
    }
    return 0;
}
