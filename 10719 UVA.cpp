#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll k,x,n,test = 0;
    string s;

    while(scanf("%lld\n",&k)==1)
    {
        vector<ll>a;

        getline(cin,s);
        n = 0;
        stringstream ss(s);

        while(ss>>x)
            n++,a.push_back(x);

        reverse(a.begin(),a.end());
        vector<ll>b(n,0);
        for(int i=n-2;i>=0;i--)
            b[i] =  b[i+1]*k + a[i+1];

        ll r = a[0] + k*b[0];
        cout<<"q(x):";
        for(int i=n-2;i>=0;i--)
            cout<<" "<<b[i];
        cout<<endl<<"r = "<<r<<endl<<endl;
    }
    return 0;
}
