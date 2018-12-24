#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll n,x,kase = 1;

    vector<ll>ara;

    while(scanf("%lld",&n)==1)
    {
        ll max_p = 0;
        ara.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            ara.push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            ll cur_p = ara[i];
            max_p = max(max_p,cur_p);
            for(int j=i+1;j<n;j++)
            {
                cur_p*=ara[j];
                max_p = max(max_p,cur_p);
            }
        }
        printf("Case #%lld: The maximum product is %lld.\n\n",kase++,max_p);
    }
    return 0;
}
