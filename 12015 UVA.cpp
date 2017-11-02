#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t,n,cycle,max;
    string s;

    scanf("%d",&t);

    for(int kase = 1;kase<=t;kase++)
    {
        vector<string>data[101];
        printf("Case #%d:\n",kase);
        cycle = 10;
        max = -1;
        while(cycle--)
        {
            cin>>s>>n;
            if(max<n)   max = n;
            data[n].push_back(s);
        }
        for(int i=0;i<data[max].size();i++)
            printf("%s\n",data[max][i].c_str());
    }

    return 0;
}
