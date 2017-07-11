#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,i,lamb[10];
    bool s,rs;

    scanf("%d",&t);
    printf("Lumberjacks:\n");

    while(t--)
    {
        rs=true; /// Reverse Sort
        s=true;  /// Sort

        for(i=0;i<10;i++)
        {
            scanf("%d",&lamb[i]);

            if(i==0)
                continue;

            if(s==true&&lamb[i]<lamb[i-1])
                s=false;

            if(rs==true&&lamb[i]>lamb[i-1])
                rs=false;
        }

        if(s||rs)
            printf("Ordered\n");

        else
            printf("Unordered\n");

    }
    return 0;
}
