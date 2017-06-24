#include<bits/stdc++.h>
using namespace std;
typedef vector<long long int> vl;
typedef long long int ll;
int nod(int n)
{
    int r= sqrt(n),count=0;
    for(int i=1;i<=r;i++)
        if(n%i==0)
            count++;
    if(r*r==n)
        return 2*count-1;
    else
        return 2*count;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    vl data;
    ll n=1, v;
    for(int i=0;i<68000;i++)
    {
        if(i==0)
        {
            data.push_back(n);
            continue;
        }
        else
        {
            v=n+nod(n);
            n=v;
        }
        data.push_back(n);
    }

    int t,a,b;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        printf("Case %d: ",i);

        b=upper_bound(data.begin(),data.end(), b)-data.begin();
        a=upper_bound(data.begin(),data.end(), a-1)-data.begin();
        printf("%d\n",b-a);
    }

    return 0;
}
