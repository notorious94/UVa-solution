#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,a,ca=0;
    vector<int>age;
    sif(t);
    while(t--)
    {
        ca++;
        sif(n);
        for(int i=0;i<n;i++)
        {
            sif(a);
            age.push_back(a);
        }
        pf("Case %d: %d\n",ca,age[age.size()/2]);
        age.clear();
    }
    return 0;
}
