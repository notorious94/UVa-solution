#include<bits/stdc++.h>
using namespace std;

int freq[10000];
int lp[10000];
vector<int>prime,pf,pff;

void sieve()
{
    for(int i=2; i<10000; i++)
    {
        if(lp[i]==0)
        {
            lp[i]=i;
            prime.push_back(i);
        }
        for(int j=0; j<prime.size()&&prime[j]<=i&&prime[j]*i<10000; j++)
            lp[i*prime[j]] = i;
    }
}

bool facto(int n,bool flag = false)
{
    int root = sqrt(n);
    for(int i=0; prime[i]<=root; i++)
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
            else
            {
                if(freq[prime[i]]>=f)
                {
                    pf.push_back(prime[i]);
                    pff.push_back(f);
                }
                else
                    return false;
            }
        }
        if(lp[n]==n&&n>1)
            break;
    }
    if(n>1)
    {
        if(flag==false)
            freq[n]++;
        else
        {
            if(freq[n])
            {
                pf.push_back(n);
                pff.push_back(1);
            }
            else
                return false;
        }
    }
    return true;
}
bool check()
{
    for(int i=0;i<pf.size();i++)
    {
        if(freq[pf[i]]>=pff[i])
            freq[pf[i]]-=pff[i];
        else
            return false;
    }
    return true;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,m,n;

    sieve();
    scanf("%d",&test);

    for(int k=1; k<=test; k++)
    {
        scanf("%d%d",&m,&n);
        printf("Case %d:\n",k);

        memset(freq,0,sizeof(freq));

        for(int i=2; i<=n; i++)
            facto(i);

        pf.clear(),pff.clear();

        if(facto(m,true)==false)
            cout<<"Impossible to divide"<<endl;
        else
        {
            int ans = 0;
            while(check())
                ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
}
