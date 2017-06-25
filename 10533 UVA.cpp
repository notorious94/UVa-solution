#include<bits/stdc++.h>
using namespace std;

int sum(char c[])
{
    int sum=0;
    for(int i=0;c[i]!='\0';i++)
        sum+=(c[i]-'0');
    return sum;
}

int main()
{
    //freopen("d:\\in.txt", "r", stdin);
    //freopen("d:\\out.txt","w", stdout);

    vector<bool>prime(1000001,true);
    int root=sqrt(1000001);

    prime[0]=false;
    prime[1]=false;

    for(int i=2;i<=root;i++)
        if(prime[i])
            for(int j=2;i*j<1000001;j++)
                prime[i*j]=false;

    vector<int>dprime(1000001,0);

    dprime[0]=1000001;
    dprime[1]=1000001; /// Initializing with MAX+1

    for(int i=2;i<1000001;i++)
    {
        dprime[i]=1000001; /// Initializing with MAX+1
        if(prime[i])
        {
            char d[20];
            sprintf(d,"%d",i); /// Converting prime into strings
            if(prime[sum(d)]) /// Checking whether the sum is also prime or not
                dprime[i]=i;  /// Replacing with Prime value
        }
    }

    sort(dprime.begin(), dprime.end());

    int a, b, t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);

        b=upper_bound(dprime.begin(),dprime.begin()+30124, b)-dprime.begin();
        a=upper_bound(dprime.begin(),dprime.begin()+30124, a-1)-dprime.begin();

        printf("%d\n",b-a);
    }
    return 0;
}
