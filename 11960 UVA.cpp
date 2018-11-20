#include<bits/stdc++.h>
using namespace std;

int ans[1000001];
int lp[1000001];
vector<int>prime;

void sieve(int limit = 1000001)
{
    for(int i=2; i<limit; i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0; j<prime.size()&&prime[j]<=i&&i*prime[j]<limit; j++)
            lp[i*prime[j]]=i;
    }
}

void primef()
{
    ans[1] = 1;
    int max_div = 1,max_e = 1;

    for(int i=2;i<=1000000;i++)
    {
        int total_div = 1;
        if(lp[i]==i)
            total_div = 2;
        else
        {
            int n = i,r = sqrt(i);
            for(int j=0; j<prime.size()&&prime[j]<=r; j++)
            {
                if(n%prime[j]==0)
                {
                    int f = 1;
                    while(n%prime[j]==0)
                    {
                        n/=prime[j];
                        f++;
                    }
                    total_div*=f;
                    if(lp[n]==n)    break;
                }
            }
            if(n>1) total_div*=2;
        }
        if(total_div>=max_div)
        {
            ans[i] = max_e = i;
            max_div = total_div;
        }
        else    ans[i] = max_e;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieve();
    primef();

    int test,N;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&N);
        printf("%d\n",ans[N]);
    }
    return 0;
}
