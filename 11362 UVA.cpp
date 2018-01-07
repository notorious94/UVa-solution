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

    char n[50];
    vector<string>number;
    int t,l;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&l);
        number.clear();

        bool answer = false;

        for(int i=0;i<l;++i)
        {
            scanf("%s",n);
            number.push_back(n);
        }

        for(int i=0;i<l-1;i++)
        {
            for(int j=i+1;j<l;j++)
            {
                if(number[i].size()<=number[j].size())
                {
                    bool match = true;
                    for(int a=0;number[i][a];a++)
                    {
                        if(number[i][a]!=number[j][a])
                        {
                            match = false;
                            break;
                        }
                    }
                    if(match)
                    {
                        answer=true;
                        break;
                    }
                }
                else if(number[j].size()<=number[i].size())
                {
                    bool match = true;
                    for(int a=0;number[j][a];a++)
                    {
                        if(number[i][a]!=number[j][a])
                        {
                            match = false;
                            break;
                        }
                    }
                    if(match)
                    {
                        answer=true;
                        break;
                    }
                }
            }
            if(answer)  break;
        }
        if(answer)
            pf("NO\n");
        else
            pf("YES\n");
    }

    return 0;
}
