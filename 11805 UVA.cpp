#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n,k,p,t,c=0,r;
    scanf("%d",&t);
    while(t--)
    {
        c++;
        scanf("%d%d%d",&n,&k,&p);
        printf("Case %d: ",c);
        r=(p%n)+k;
        if(r<=n)
            printf("%d\n",r);
        else
            printf("%d\n",r-n);
    }
    return 0;
}
