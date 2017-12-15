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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,l,m,n;
    char side[500];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&m);
        l*=100;
        int capacity = l,ferry = 0;
        deque<int>left,right;

        for(int i=0;i<m;i++)
        {
            scanf("%d%s",&n,&side);

            if(side[0]=='l')
                left.push_back(n);
            else
                right.push_back(n);
        }

        while(m)
        {
            capacity = l;
            if(left.size())
                while(capacity>=left.front())
                {
                    m--;
                    capacity-=left.front();
                    left.pop_front();
                    if(left.empty())    break;
                };
            capacity = l;
            ferry++;
            if(!m)  break;
            if(right.size())
                while(capacity>=right.front())
                {
                    m--;
                    capacity-=right.front();
                    right.pop_front();
                    if(right.empty())
                        break;
                }
            ferry++;
        }
        pif(ferry);
    }
    return 0;
}
