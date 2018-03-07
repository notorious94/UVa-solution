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

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,+1,-1,-1,+1,-1,+1};

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

    int t;
    char s[5000];
    scanf("%d\n\n",&t);
    while(t)
    {
        vector<string>bank;

        while(gets (s) && strlen (s))
            bank.push_back(s);
        sort(all(bank));
        for(int i=0;i<bank.size()-1;i++)
        {
            string t1;
            for(int k=0;bank[i][k];k++)
                if(bank[i][k]!=32)
                    t1+=bank[i][k];

            sort(all(t1));
            for(int j=i+1;j<bank.size();j++)
            {
                string t2;
                for(int k=0;bank[j][k];k++)
                    if(bank[j][k]!=32)
                        t2+=bank[j][k];
                sort(all(t2));

                if(t1==t2)
                    printf("%s = %s\n",bank[i].c_str(),bank[j].c_str());
            }
        }
        if(--t)
            puts("");
    }
    /*char str[] ="This a sample string";
    char * pch;
    //printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ");
    while (pch)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
    }*/

    return 0;
}
