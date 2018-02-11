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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int kase = 0, p,c,item;
    char s[5];
    list<int>l;
    list<int> :: iterator it;
    while(scanf("%d%d",&p,&c)==2)
    {
        if(!p && !c)    break;
        l.clear();
        int limit = min(1000,p);
        for(int i=1;i<=limit;i++)
            l.insert(l.end(),i);
        pf("Case %d:\n",++kase);
        while(c--)
        {
            scanf("%s",s);
            if(s[0]=='N')
            {
                it = l.begin();
                pif(*it);
                l.insert(l.end(),*it);
                l.erase(it);
            }
            else{
                sif(item);
                it = find(l.begin(),l.end(),item);
                if(it!=l.end())
                {
                    l.erase(it);
                    it = l.begin();
                    l.insert(it,item);
                }
                else{
                    it = l.begin();
                    l.insert(it,item);
                }
            }
        }
    }
    return 0;
}
