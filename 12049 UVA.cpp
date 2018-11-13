#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<ll,int>f1,f2;
unordered_map<ll,int> :: iterator it,it2;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test;

    scanf("%d",&test);

    while(test--)
    {
        int n,m;
        ll a;

        scanf("%d%d",&n,&m);

        f1.clear();
        f2.clear();

        while(n--)
        {
            scanf("%lld",&a);
            f1[a]++;
        }

        while(m--)
        {
            scanf("%lld",&a);
            f2[a]++;
        }
        int ans = 0;
        for(it = f1.begin();it!=f1.end();it++)
        {
            int x = it->second, y = f2[it->first];
            ans += abs(x-y);
            if(f2.find(it->first)!=f2.end())
                f2.erase(it->first);
        }
        for(it = f2.begin();it!=f2.end();it++)
            ans += it->second;
        cout<<ans<<endl;
    }

    return 0;
}
