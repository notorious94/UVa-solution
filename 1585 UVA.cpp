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
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[100];
    int t;
    vector<int>sum;

    sif(t);

    while(t--)
    {
        scanf("%s",s);

        for(int i=0;s[i];i++)
        {
            if(!i)
            {
                if(s[i]=='X')
                    sum.push_back(0);
                else
                    sum.push_back(1);
            }

            else if(s[i]=='X')
                sum.push_back(0);

            else
            {
                int temp = sum[sum.size()-1];
                sum.push_back(temp+1);
            }
        }

        int ans=0;

        for(int i=0;i<sum.size();i++)
            ans+=sum[i];

        pif(ans);

        sum.clear();
    }

    return 0;
}
