#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int lp[50001];
vector<int>prime;

void sieve(int limit = 50001)
{
    for(int i=2;i<limit;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&i*prime[j]<limit;j++)
            lp[i*prime[j]]=i;
    }
}

map<int,int>freq;
map<int,int> :: const_iterator it;

void factorize(int d)
{
    int r = sqrt(d);
    for(int i=0;i<prime.size()&&prime[i]<=r;i++)
    {
        if(d%prime[i]==0)
        {
            int f = 0;
            while(d%prime[i]==0)
            {
                f++;
                d/=prime[i];
            }
            freq[prime[i]]+=f;

        }
    }
    if(d>1) freq[d]++;
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieve();
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n)
        {
            if(m>1) printf("%d does not divide %d!\n",m,n);
            else    printf("%d divides %d!\n",m,n);
            continue;
        }
        freq.clear();
        factorize(m);
        bool flag = true;
        for(it = freq.begin();it!=freq.end();it++)
        {
            ll primefactor = it->first;
            ll frequecny = it->second;
            int sum_of_freq = 0;

            for(ll j=1;j*primefactor<=n;j++)
            {
                ll number = j*primefactor;
                while(number%primefactor==0)
                {
                    sum_of_freq++;
                    if(sum_of_freq>=frequecny)
                        break;
                    number/=primefactor;
                }
                if(sum_of_freq>=frequecny)
                    break;
            }
            if(sum_of_freq<frequecny)
            {
                flag = false;
                break;
            }
        }
        (flag) ? printf("%d divides %d!\n",m,n) : printf("%d does not divide %d!\n",m,n);
    }
    return 0;
}
