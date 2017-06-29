#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int a[3],t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d", &a[0],&a[1],&a[2]);

        sort(a, a+3);

        if(a[0]+a[1]>a[2])
            printf("OK\n");
        else
            printf("Wrong!!\n");
    }
    return 0;
}

