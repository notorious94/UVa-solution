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
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,w;
    char s[50];
    scanf("%d",&t);
    while(t--)
    {
        map<string,vector<string> >solution;
        scanf("%d",&w);
        while(w--)
        {
            scanf("%s",s);
            string t;
            for(int i=0;s[i];i++)
                t+=tolower(s[i]);
            sort(all(t));
            solution[t].push_back(s);
        }
        while(scanf("%s",s))
        {
            if(!strcmp(s,"END"))    break;
            string t;
            for(int i=0;s[i];i++)
                t+=tolower(s[i]);
            sort(all(t));
            printf("Anagrams for: %s\n",s);
            if(solution[t].size()==0)
                printf("No anagrams for: %s\n",s);
            else
                for(int i=1;i<=solution[t].size();i++)
                    printf("  %d) %s\n",i,solution[t][i-1].c_str());
        }
        if(t)   puts("");
    }
    return 0;
}
