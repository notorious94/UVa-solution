#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int lp[1000];
vector<int>prime;

void sieve()
{
    for(int i=2;i<1000;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&prime[j]*i<1000;j++)
        {
            lp[i*prime[j]] = i;
        }
    }
}

int freq[1000];

void facto(int n)
{
    if(n==1)    return;
    int r = sqrt(n);
    for(int i=0;prime.size()&&prime[i]<=r;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                freq[prime[i]]++;
                n/=prime[i];
            }
            if(lp[n]==n&&n>1) {
                break;
            }
        }
    }
    if(n>1)
        freq[n]++;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieve();
    int test;
    char s[100];
    scanf("%d",&test);

    for(int kase=1;kase<=test;kase++)
    {
        scanf("%s",s);
        int k = 0;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='!')
            {
                k = (strlen(s)-i);
                break;
            }
        }

        memset(freq,0,sizeof(freq));

        int n = atoi(s);

        facto(n);

        for(int i=1;n-k*i>1;i++)
            facto(n-k*i);

        ll res = 1,limit = 1e18;

        for(int i=0;prime[i]<=n;i++)
        {
            if(freq[prime[i]])
            {

                res*=(1+freq[prime[i]]);
                if(res>limit)
                {
                    res = -1;
                    break;
                }
            }
        }
        printf("Case %d: ",kase);
        if(res<0)
            puts("Infinity");
        else
            cout<<res<<endl;
    }
}
