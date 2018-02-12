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

    list<char>name;
    list<char> :: iterator it;

    int t,n,m;
    char s[505];
    scanf("%d",&t);
    for(int kase = 1;kase<=t;kase++)
    {
        scanf("%d%d%s",&n,&m,s);
        name.clear();
        printf("Case %d: ",kase);

        int ans = 0;

        for(int i=0;s[i];i++)
        {
            it = find(name.begin(),name.end(),s[i]);
            if(it != name.end())
                ans++;
            if(name.size()>=m)
            {
                it = name.begin();
                name.erase(it);
            }
            name.insert(name.end(),s[i]);
        }
        printf("%d\n",ans);
    }

    return 0;
}
