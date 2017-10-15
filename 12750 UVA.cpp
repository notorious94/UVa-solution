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

    int t,n;
    scanf("%d",&t);
    char c;
    string s;

    for(int cn=1;cn<=t;cn++)
    {
        printf("Case %d: ",cn);
        scanf("%d",&n);
        int i,count=0;

        while(n--)
        {
            scanf(" %c",&c);
            s+=c;
        }

        for(i=0;s[i];i++)
        {
            if(s[i]!='W')   count++;
            else            count=0;
            if(count>=3)
            {
                cout<<i+1<<endl;
                break;
            }
        }

        if(i==s.size())
            printf("Yay! Mighty Rafa persists!\n");

        s.clear();
    }

    return 0;
}
