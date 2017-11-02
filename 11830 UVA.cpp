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

    char n[2],s[MAX];

    while(scanf("%s %s",n,s))
    {
        if(!strcmp(n,"0") && !strcmp(s,"0"))
            break;

        bool print = false, trail_zero=false;

        for(int i=0;s[i];i++)
        {
            if(trail_zero==true && s[i]!=n[0])      printf("%c",s[i]);
            else if(trail_zero==false && s[i]!=48 && s[i]!=n[0])
            {
                print = trail_zero = true;
                printf("%c",s[i]);
            }
        }
        if(print==false)    printf("0");
        printf("\n");
    }

    return 0;
}
