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

typedef long long ll;
typedef unsigned long long ull;

void fact(int n)
{
    set<int>f;
    set<int>:: iterator it;
    int r = sqrt(n);
    for(int i=2;i<=r;i++)
    {
        if(n%i==0)
        {
            f.insert(n/i);
            f.insert(i);
            if(f.size()==4)
                break;
        }
    }
    it = f.begin();
    int a = *it;
    it++;
    int b = n/a;
    it++;
    int c = *it;
    it++;
    int d = n/c;
    pf("%d = %d * %d = %d * %d\n",n,a,b,c,d);
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    sif(t);
    for(int k=1;k<=t;k++)
    {
        sif(n);
        pf("Case #%d: ",k);
        fact(n);
    }
    return 0;
}
