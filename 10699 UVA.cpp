#include<bits/stdc++.h>
using namespace std;

int n;
int pf()
{
    int count=0, r=sqrt(n);
    for(int i=2;i<=r;i++)
    {
        if(n%i==0)
        {
            count++;
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        count++;
    return count;
}

int main()
{
     //freopen("input.txt", "r", stdin);
     //freopen("out.txt", "w", stdout);
     while(1)
     {
         scanf("%d",&n);
         if(n==0)
            break;
         printf("%d : ",n);
         printf("%d\n",pf());
     }
     return 0;
}
