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

    int d[101];
    char s[100];
    int t,i,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&i);
        int p = 0;

        for(int n=1;n<=i;n++)
        {
            scanf("%s",s);

            if(s[0]=='L')
                d[n] = -1;
            else if(s[0]=='R')
                d[n] = 1;
            else
            {
                scanf("%s%d",s,&c);
                d[n] = d[c];
            }

            p+=d[n];
        }
        pf("%d\n",p);
    }

    return 0;
}
