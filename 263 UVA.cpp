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
    char s[50];
    string t;
    set<int>result;
    set<int>::iterator it;

    while(scanf("%s",s))
    {
        if(s[0]==48)    break;

        printf("Original number was %s\n",s);

        result.clear();
        bool flag = true;
        t = s;

        while(flag)
        {
            sort(t.begin(),t.end());
            int b = atoi(t.c_str());
            reverse(t.begin(),t.end());
            int a = atoi(t.c_str());

            int r = a-b;

            printf("%d - %d = %d\n",a,b,r);

            it = result.find(r);

            if(it != result.end())
                flag = false;
            else
            {
                result.insert(r);
                char buff[50];
                sprintf (buff,"%d",r);
                t = buff;
            }
        }

        printf("Chain length %d\n\n",result.size()+1);
    }
    return 0;
}
