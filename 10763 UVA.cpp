#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,t;
    pii temp;

    vector<pii> ab,ba;

    while(scanf("%d",&t))
    {
        if(!t)  break;

        while(t--)
        {
            scanf("%d%d",&a,&b);
            temp.first = a;
            temp.second = b;
            ab.push_back(temp);
            temp.first = b;
            temp.second = a;
            ba.push_back(temp);
        }

        sort(ab.begin(),ab.end());
        sort(ba.begin(),ba.end());

        if(ab==ba)
            printf("YES\n");
        else
            printf("NO\n");

        ab.clear();
        ba.clear();
    }

    return 0;
}
