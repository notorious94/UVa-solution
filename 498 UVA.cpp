#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll>a,X;

ll HornorsMethod(ll n,ll x)
{
    /// P[n] = a[n]
    /// P[n-1] = P[n]*x + a[n-1]
    /// ........................
    /// ........................
    /// ........................
    /// ........................
    /// ........................
    /// P[1] = P[2]*x + a[1]
    /// P[0] = P[1]*x + a[0]

    ll P[n+1] = {0};
    P[n] = a[n];
    while(n--)
        P[n] = P[n+1]*x + a[n];
    return P[0];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll n;
    string s1,s2;

    while(getline(cin,s1))
    {
        a.clear();
        X.clear();

        getline(cin,s2);
        stringstream ss(s1),ss1(s2);

        /// Input Processing
        while(ss>>n)
            a.push_back(n);
        reverse(a.begin(),a.end());

        while(ss1>>n)
            X.push_back(HornorsMethod(a.size()-1,n));

        /// Output Processing
        cout<<X[0];
        for(int i=1;i<X.size();i++)
            cout<<" "<<X[i];
        cout<<endl;
    }

    return 0;
}
