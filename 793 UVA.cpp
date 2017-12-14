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

int Parent[1000001], Rank[1000001];
int Find(int a)
{
    return (Parent[a]==a) ? a : Parent[a] = Find(Parent[a]);
}
void makeUnion(int a, int b)
{
    int u = Find(a);
    int v = Find(b);

    if(u==v)    return;

    if(Rank[u]>Rank[v]) Parent[v] = u;
    else    Parent[u] = v;

    if(Rank[u]==Rank[v])    ++Rank[v];
    return;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    char s[MAX];
    char c;
    int t,n,a,b;
    int wrong,right;

    scanf("%d\n\n",&t);
    while(t--)
    {
        scanf("%d\n",&n);

        for(int i=1;i<=n;++i){
            Parent[i]=i;
            Rank[i] = 1;
        }

        right = wrong = 0;

        while(true)
        {
            if(!gets(s) || !s[0])
                break;

            sscanf(s,"%c %d %d",&c,&a,&b);

            if(c=='c')
                makeUnion(a,b);

            else
            {
                if(Find(a)!=Find(b))    wrong++;
                else right++;
            }

        }

        pf("%d,%d\n",right,wrong);

        if(t)   pf("\n");

    }
    return 0;
}
