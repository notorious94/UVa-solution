#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>a,X;
ll HornorsMethod(ll n,ll x)
{
    ll n1 = a.back(),n2;
    while(n--)
    {
        n2 = n1*x+a[n+1];
        n1 = n2;
    }
    return n1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string s1,s2;
    while(getline(cin,s1))
    {
        getline(cin,s2);

        a.clear(),X.clear();

        stringstream ss1(s1),ss2(s2);

        ll n;

        while(ss1>>n)
            X.push_back(n);

        while(ss2>>n)
            a.push_back(n);

        reverse(a.begin(),a.end());

        for(int i=0;i<a.size();i++)
            a[i]*=i;

        if(a.size()<=2)
        {
            cout<<a.back();
            for(int i=1;i<X.size();i++)
                cout<<" "<<a.back();
            cout<<endl;
        }

        else
        {
            vector<ll>result;

            for(int i=0;i<X.size();++i)
                result.push_back(HornorsMethod(a.size()-2,X[i]));
            cout<<result[0];
            for(int i=1;i<result.size();i++)
                cout<<" "<<result[i];
            cout<<endl;
        }

    }
    return 0;
}
