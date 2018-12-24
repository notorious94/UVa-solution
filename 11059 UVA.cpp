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
        ara.clear();

        for(int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            ara.push_back(x);
        }

        ll maxValue,minValue,maxProduct = 0;

        maxValue = ara[0];
        minValue = ara[0];

        maxProduct = max(maxProduct,ara[0]);

        for(int i=1;i<n;i++)
        {
            if(ara[i]<0)    swap(minValue,maxValue);

            minValue = min(ara[i],minValue*ara[i]);
            maxValue = max(ara[i],maxValue*ara[i]);

            maxProduct = max(maxProduct,maxValue);
        }
        printf("Case #%lld: The maximum product is %lld.\n\n",kase++,maxProduct);
    }

    return 0;
}
