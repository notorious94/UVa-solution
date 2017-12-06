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

class loc{
public:
    int r,c,v;
    loc(int x,int y,int n){
        r = x;
        c = y;
        v = n;
    }
};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int , vector<loc> > transpose;

    int m,n,total_col,a;
    while(sf("%d%d",&m,&n)!=EOF)
    {
        for(int r = 1;r<=m;r++)
        {
            scanf("%d",&total_col);

            int col[total_col];

            for(int c=0;c<total_col;c++)
                scanf("%d",&col[c]);

            for(int c=0;c<total_col;c++)
            {
                scanf("%d",&a);
                transpose[col[c]].push_back(loc(col[c],r,a));
            }
        }

        pf("%d %d\n",n,m);

        for(int x=1;x<=n;x++)
        {
            int limit = transpose[x].size();

            pf("%d",limit);

            if(!limit){
                pf("\n\n");
                continue;
            }

            for(int i=0;i<limit;i++)
                pf(" %d",transpose[x][i].c);
            pf("\n");

            for(int i=0;i<limit-1;i++)
                pf("%d ",transpose[x][i].v);
            pf("%d\n",transpose[x][limit-1].v);

        }
        transpose.clear();
    }
    return 0;
}
