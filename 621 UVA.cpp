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

    char s[MAX*2];
    int t;

    sif(t);
    while(t--)
    {
        scanf("%s",s);

        int len = strlen(s);

        if(!strcmp(s,"1")||!strcmp(s,"4")||!strcmp(s,"78"))
        {
            printf("+\n");
            continue;
        }

        else if(len==2)
        {
            if(s[0]=='3' and s[1]=='5')
            {
                printf("-\n");
                continue;
            }
            else if(s[0]=='9' and s[1]=='4')
            {
                printf("*\n");
                continue;
            }
            else
            {
                printf("?\n");
                continue;
            }
        }
        else
        {
            if(s[len-2]=='3' and s[len-1]=='5')
            {
                printf("-\n");
                continue;
            }
            else if (s[0]=='9' and s[len-1]=='4')
            {
                printf("*\n");
                continue;
            }
            else if(s[0]=='1' and s[1]=='9' and s[2]=='0')
            {
                printf("?\n");
                continue;
            }
            else
            {
                printf("?\n");
                continue;
            }
        }
    }

    return 0;
}
