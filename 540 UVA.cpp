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
int ID[1000000];
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char cmd[100];
    int t,item;
    int member,kase = 0;
    while(scanf("%d",&t)!=EOF)
    {
        if(!t)  break;

        queue<int>q[t+1];
        queue<int>Q;

        for(int i=1;i<=t;i++)
        {
            scanf("%d",&member);
            while(member--)
            {
                scanf("%d",&item);
                ID[item] = i;
            }
        }

        pf("Scenario #%d\n",++kase);

        while(scanf("%s",cmd))
        {
            if(cmd[0]=='S')
                break;

            if(cmd[0]=='E')
            {
                scanf("%d",&item);
                int id = ID[item];
                if(q[id].empty())
                {
                    q[id].push(item);
                    Q.push(id);
                }
                else
                    q[id].push(item);
            }

            if(cmd[0]=='D')
            {
                int id = Q.front();
                if(q[id].size()==1)
                {
                    pf("%d\n",q[id].front());
                    q[id].pop();
                    Q.pop();
                }
                else
                {
                    pf("%d\n",q[id].front());
                    q[id].pop();
                }
            }
        }
        pf("\n");
    }
    return 0;
}
