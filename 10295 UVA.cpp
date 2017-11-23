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

    int m,n,money;
    char s[MAX];

    map<string,int>words;
    vector<string>data;

    while(scanf("%d%d",&m,&n)!=EOF)
    {
        while(m--)
        {
            scanf("%s%d",s,&money);
            words[s] = money;
            data.push_back(s);
        }

        sort(data.begin(),data.end());

        while(n!=0)
        {
            int sum = 0;

            while(true)
            {
                scanf("%s",s);
                if(s[0]=='.')   {
                    pif(sum);
                    n--;
                    break;
                }

                if(binary_search(data.begin(),data.end(),s))
                    sum += words[s];
            }
        }
        data.clear();
        words.clear();
    }
    return 0;
}
