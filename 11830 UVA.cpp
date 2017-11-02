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

    char n[50],s[MAX];
    map<char, vector<int> >digit;

    while(scanf("%s %s",n,s))
    {
        if(!strcmp(n,"0") && !strcmp(s,"0"))
            break;

        for(int i = 0; s[i] ; i++)
            digit[s[i]].push_back(i);

        for(int i=0;i<digit[n[0]].size();i++)
            s[digit[n[0]][i]] = 'X';

        bool p = false;
        bool trailZero = false;

        for(int i=0;s[i];i++)
        {
            if(s[i]!='X' && s[i]!=48)
            {
                trailZero = p = true;
                printf("%c",s[i]);
                continue;
            }
            else if(trailZero && s[i]!='X')     printf("%c",s[i]);
        }

        if(!p)  printf("0");
        printf("\n");
        digit.clear();
    }

    return 0;
}
