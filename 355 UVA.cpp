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

string pos = "0123456789ABCDEF";

bool check_base(char s[],int from)
{
    int b,base=0;

    for(int i=0;s[i];i++)
    {
        if(isalpha(s[i]))   b = s[i]-'A'+11;
        else    b= s[i]-48+1;

        if(b>base)  base = b;
        if(base>from)   return false;
    }

    return true;
}

double Decimal(char s[], int from)
{
    int power = strlen(s)-1;
    double dec = 0, d;

    for(int i=0;s[i];i++)
    {
        if(s[i]!=48)
        {
            if(isalpha(s[i]))   d = s[i]-'A'+10;
            else   d = s[i]-'0';

            dec += ceil(d*pow(from,power));
        }
        power--;
    }
    return dec;
}

string convert(double decimal, int to)
{
    if(!decimal) return "0";
    int m;
    string s;
    ull d = (ull)decimal;
    while(d)
    {
        m = d%to;
        d/=to;
        s.push_back(pos[m]);
    }
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int from, to;
    char n[20];

    while(scanf("%d %d %s",&from,&to,&n)!=EOF)
    {
        if(!check_base(n,from))
        {
            printf("%s is an illegal base %d number\n",n,from);
            continue;
        }
        double decimal = Decimal(n,from);
        printf("%s base %d = ",n,from);
        if(to==10)
        {
            printf("%.lf base %d\n",decimal,to);
            continue;
        }
        string ans = convert(decimal,to);
        printf("%s base %d\n",ans.c_str(),to);
    }
    return 0;
}
