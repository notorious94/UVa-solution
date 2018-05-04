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
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int p[100001],r[100001];

int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}

bool make_pair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);

    if(u==v)    return false;
    if(r[u]>=r[v])
        p[v] = p[u], r[u] += r[v];
    else
        p[u] = p[v], r[v] += r[u];
    return true;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,reject = 0;

    for(int i=0;i<100001;i++)
        p[i] = i , r[i] = 1;

    while(scanf("%d",&a)==1)
    {
        if(a==-1)
        {
            pif(reject);
            for(int i=0;i<100001;i++)
                p[i] = i , r[i] = 1;
            reject = 0;
        }
        else
        {
            scanf("%d",&b);
            if(!make_pair(a,b)) reject++;
        }
    }
    return 0;
}
