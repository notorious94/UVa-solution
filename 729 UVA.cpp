#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t,n,b;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&b);
        string s;
        for(int i=1;i<=n-b;i++) s+='0';
        for(int i=1;i<=b;i++)   s+='1';
        bool f = true;
        while(f)
        {
            pf("%s\n",s.c_str());
            f = next_permutation(s.begin(),s.end());
        }
        if(t)   cout<<endl;
    }

    return 0;
}
