#include<bits/stdc++.h>
using namespace std;

int a,b,c,d,l;

int main()
{

    int count;

    while(scanf("%d%d%d%d%d", &a,&b,&c,&d,&l))
    {
        if(a==0&&b==0&&c==0&&d==0&&l==0)
            break;

        count=0;

        for(int i=0;i<=l;i++)
            if((a*i*i+b*i+c)%d==0)
                count++;

        printf("%d\n",count);
    }

    return 0;
}
