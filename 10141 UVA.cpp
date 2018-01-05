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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ans;
    char s[MAX],name[MAX];
    int kase = 0,n,p;

    while(sf("%d%d\n",&n,&p))
    {
        if(!n&&!p)  break;

        kase++;

        if(kase>1)  pf("\n");

        for(int i=1;i<=n;i++)
            gets(s);

        double m, r, money, c, compliance = -1.0;

        for(int i=1;i<=p;i++)
        {
            gets(name);
            sf("%lf%lf\n",&m,&r);

            for(int j=1;j<=(int)r;j++)
                gets(s);

            c = r/(double)(1.0*n);
            if(c>compliance)
            {
                ans = name;
                money = m;
                compliance = c;
            }
            else if(c==compliance && m < money)
            {
                money = m;
                ans = name;
            }
        }
        pf("RFP #%d\n",kase);
        pf("%s\n",ans.c_str());
    }
    return 0;
}
