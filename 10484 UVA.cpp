#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int freq[100];
int lp[46350];
vector<int>prime;

void sieve()
{
    for(int i=2; i<46350; i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0; j<prime.size()&&i*prime[j]<46350&&prime[j]<=i; j++)
            lp[prime[j]*i] = i;
    }
    /*for(int i=0; prime[i]<=100; i++)
        cout<<prime[i]<<endl;*/
}

bool factorize(int n,bool flag = false)
{
    int root = sqrt(n);
    for(int i=0; i<prime.size()&&prime[i]<=root; i++)
    {
        if(n%prime[i]==0)
        {
            int f = 0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                f++;
            }
            if(flag==false)
                freq[prime[i]]+=f;
            else if(prime[i]>97)
                return false;
            else if(freq[prime[i]]>=f)
                freq[prime[i]]-=f;
            else
                return false;
        }
    }

    if(n>1)
    {
        if(flag==false)
            freq[n]++;
        else if(n>97)
            return false;
        else if(freq[n])
            freq[n]--;
        else
            return false;
    }
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    sieve();

    int k,d;

    while(scanf("%d%d",&k,&d))
    {
        if(!k&&!d)  break;

        if(k==0&&d==1)
        {
            puts("1");
            continue;
        }

        memset(freq,0,sizeof(freq));

        for(int i=2;i<=k;i++)
            factorize(i);

        if(factorize(abs(d),true))
        {
            ll res = 1;
            for(int i=0;prime[i]<=97;i++)
            {
                if(freq[prime[i]])
                    res*=(1+freq[prime[i]]);
            }
            printf("%lld\n",res);
        }
        else
            puts("0");
    }

    return 0;
}
