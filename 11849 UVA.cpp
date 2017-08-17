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

    int a,b,n,count=0;

    vector<int>jack;

    while(sf("%d%d",&a,&b))
    {
        if(!a&&!b)
            break;

        for(int i=0;i<a;i++)
        {
            sif(n);
            jack.push_back(n);
        }
        sort(jack.begin(),jack.end());
        count=0;
        for(int i=0;i<b;i++)
        {
            sif(n);
            if(binary_search(jack.begin(),jack.end(),n))
                count++;
        }
        pif(count);
        jack.clear();
    }
    return 0;
}
