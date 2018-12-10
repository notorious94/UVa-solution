#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test,n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        int small = 0,ara[n];

        for(int i=0;i<n;i++)
        {
            cin>>ara[i];

            for(int j=i-1;j>=0;j--)
            {
                if(ara[j]<=ara[i])  small++;
            }
        }
        cout<<small<<endl;
    }
    return 0;
}
