#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int test, i;

    cin>>test;
    for(i=1;i<=test;i++)
    {
        int *egg,j,n,p,q,weight=0,count=0;
        cin>>n>>p>>q;

        egg=(int*)malloc(4*n);

        for(j=0;j<n;j++)
        {
            cin>>egg[j];
            if(weight<=q)
            {
                weight+=egg[j];
                count++;
            }
        }

        while(1)
        {
            if(count<=p&&weight<=q)
            {
                printf("Case %d: %d\n",i,count);
                break;
            }
            else
            {
                weight-=egg[count-1];
                count--;
            }
        }
        free(egg);
    }
    return 0;
}
