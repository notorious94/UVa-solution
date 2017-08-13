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

    int n,v;
    vector<int>age;

    while(1)
    {
        sif(n);
        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            sif(v);
            age.push_back(v);
        }
        sort(age.begin(), age.end());
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
                pf("%d\n",age[i]);
            else
                pf("%d ", age[i]);
        }
        age.clear();
    }

    return 0;
}
