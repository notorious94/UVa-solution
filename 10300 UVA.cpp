#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll test,sum,t,a,b,c;
    scanf("%lld", &test);
    while(test--)
    {
        sum=0;
        scanf("%lld", &t);
        while(t--)
        {
            scanf("%lld%lld%lld", &a,&b,&c);
            sum+=a*c;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
