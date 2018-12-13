#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int lp[32768];
vector<int>prime;
vector<pii>result;
vector<pii> :: iterator it;

void sieve()
{
    for(int i=2;i<32768;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<32768&&prime[j]<=i;j++)
            lp[i*prime[j]] = i;
    }
}

int factorize(int num)
{
    result.clear();
    for(int i=0,root = sqrt(--num);prime[i]<=root;i++)
    {
        if(num%prime[i]==0)
        {
            int f = 0;
            while(num%prime[i]==0)
            {
                num/=prime[i];
                f++;
            }
            result.push_back({prime[i],f});
        }
    }

    if(num>1)
    {
        int loc = lower_bound(prime.begin(),prime.end(),num) - prime.begin();
        result.push_back({prime[loc],1});
    }

    sort(result.rbegin(),result.rend());
    printf("%d %d",result[0].first,result[0].second);
    for(int i=1;i<result.size();i++)
        printf(" %d %d",result[i].first,result[i].second);
    cout<<endl;
    return 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    sieve();
    string s;
    while(getline(cin,s))
    {
        if(s[0]=='0')   break;
        stringstream ss(s);
        int p,e,num = 1;
        while(ss>>p)
        {
            ss>>e;
            int expo = 1;
            for(int i=1;i<=e;i++)
                num*=p;
        }
        (num==2) ? puts("") : factorize(num);
    }
    return 0;
}
