#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 1000000
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

    map<string,int>freq;
    int n;
    char s[MAX];

    while(scanf("%d%s",&n,s)==2)
    {
        string t,pas;
        freq.clear();
        int ans=0;
        int l = strlen(s)-n;
        for(int i=0;i<l+1;i++)
        {
            t.clear();
            t+=s[i];
            if(t.size()==n)
            {
                int f = ++freq[t];
                if(f>ans)
                {
                    ans = f;
                    pas = t;
                }
            }
            for(int j=i+1;s[j];j++)
            {
                t+=s[j];
                if(t.size()==n)
                {
                    int f = ++freq[t];
                    if(f>ans)
                    {
                        ans = f;
                        pas = t;
                    }
                    break;
                }
            }
        }
        pf("%s\n",pas.c_str());
    }

    return 0;
}
