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

int Base(string s)
{
    int base = 0,b;
    for(int i=0;s[i];i++)
    {
        if(isalpha(s[i]))
            b = s[i]-'A'+10;
        else
            b = s[i]-48;

        if(b>base)
            base=b;
    }
    return 1+base;
}

double Decimal(string s, int base)
{
    double decimal=0,d;
    double power = s.size()-1;
    for(int i=0;s[i];i++)
    {
        if(s[i]!=48)
        {
            if(isalpha(s[i]))   d=s[i]-'A'+10;
            else    d=s[i]-48;
            decimal +=(d*pow(base,power));
        }
        power--;
    }
    return decimal;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    string x,y;

    while(cin>>x>>y)
    {
        if(x=="0" && y=="0")
        {
            printf("%s (base 2) = %s (base 2)\n",x.c_str(),y.c_str());
            continue;
        }

        int basex = Base(x);
        int basey = Base(y);
        double decx = Decimal(x,basex);
        double decy = Decimal(y,basey);

        bool p = false;

        for(int i=basex;i<=36;i++)
        {
            for(int j=basey;j<=36;j++)
            {
                if(Decimal(x,i)==Decimal(y,j))
                {
                    printf("%s (base %d) = %s (base %d)\n",x.c_str(),i,y.c_str(),j);
                    p=true;
                    break;
                }
            }
            if(p)   break;
        }
        if(!p)
            printf("%s is not equal to %s in any base 2..36\n",x.c_str(),y.c_str());
    }
    return 0;
}
