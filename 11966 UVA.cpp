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
#define pdd pair<double, double>

typedef long long ll;
typedef unsigned long long ull;

int p[1001],Rank[1001];

double Distance(pdd a, pdd b)
{
    double x = (a.first  - b.first);
    double y = (a.second - b.second);
    return sqrt(x*x+y*y);
}

int setValue(int n)
{
    for(int i=0;i<=n;i++){
        p[i] = i;
        Rank[i] = 0;
    }
}

int Find(int a){
    return (p[a]==a) ? a : p[a] = Find(p[a]);
}

bool makeUnion(int a, int b)
{
    int u = Find(a);
    int v = Find(b);

    if(u!=v){
        if(Rank[u]>Rank[v]){
            p[v] = u;
            Rank[u]+=Rank[v];
        }
        else{
            p[u] = v;
            Rank[v]+=Rank[u];
        }
        return true;
    }
    return false;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pdd>c;
    int t,n;
    double a,b,d;
    scanf("%d",&t);

    for(int kase = 1 ;kase<=t;kase++)
    {
        pf("Case %d: ",kase);
        scanf("%d%lf",&n,&d);
        setValue(n);
        int ans = n;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&a,&b);
            c.push_back(pdd(a,b));
        }
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++){
                if(Distance(c[i],c[j])<=d)
                    if(makeUnion(i,j))
                        ans--;
            }
        pf("%d\n",ans);
        c.clear();
    }
    return 0;
}
