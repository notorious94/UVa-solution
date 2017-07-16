#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 600
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

string sum(string a, string b)
{
    string r;
    if(a.size()>b.size())
        swap(a, b);
    reverse(a.begin(),a.end());
    reverse(b.begin(), b.end());
    int carry=0, sum=0;
    for(int i=0;i<a.size();i++)
    {
        sum=(a[i]-'0')+(b[i]-'0')+carry;
        r.push_back(sum%10+'0');
        carry=sum/10;
    }
    for(int i=a.size();i<b.size();i++)
    {
        sum=(b[i]-'0')+carry;
        r.push_back(sum%10+'0');
        carry=sum/10;
    }
    if(carry)
        r.push_back(carry+'0');
    reverse(r.begin(), r.end());
    return r;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    string s="0", a;

    while(1)
    {
        cin>>a;
        if(a=="0")
        {
            cout<<s<<endl;
            break;
        }
        s = sum(s, a);
    }

    return 0;
}
