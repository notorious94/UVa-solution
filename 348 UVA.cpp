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

int row[11], col[11];
int s[11][11];
int mem[11][11];

int mcm(int i, int j)
{
    if(i>=j)
        return 0;

    if(mem[i][j])   return mem[i][j];
    int cost = INT_MAX;
    bool update;

    for(int k=i;k<j;k++)
    {
        int m1 = mcm(i,k);
        int m2 = mcm(k+1,j);
        int total = m1 + m2 + row[i] * col[k] * col[j];
        update = false;
        if(cost > total)
        {
            cost = total;
            s[i][j] = k;
        }
    }
    return mem[i][j] = cost;
}

void bracket(int i, int j)
{
    if(i==j)
    {
        pf("A%d",i);
        return;
    }
    pf("(");
    bracket(i, s[i][j]);
    pf(" x ");
    bracket(s[i][j]+1, j);
    pf(")");
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,kase = 0;
    while(sif(n))
    {
        if(!n)  break;
        kase++;
        memset(mem, 0, sizeof(mem));
        memset(s, 0, sizeof(s));

        for(int i=1;i<=n;i++)
            sf("%d%d",&row[i],&col[i]);
        mcm(1,n);
        pf("Case %d: ",kase);
        bracket(1,n);
        pf("\n");
    }

    return 0;
}
