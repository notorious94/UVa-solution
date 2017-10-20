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
int Decimal(char s[])
{
    int power = strlen(s)-1;
    int d, decimal=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]!=48)
        {
            if(isalpha(s[i]))   d = s[i]-'A'+10;
            else   d = s[i]-'0';

            decimal += ceil(d*pow(16,power));
        }
        power--;
    }
    return decimal;
}
string convert_binary(int d)
{
    if(d==0)    return "0000000000000";
    int m;
    string s;
    while(d)
    {
        m=d%2;
        d/=2;
        (m) ? s+='1' : s+='0';
    }
    reverse(s.begin(),s.end());
    int appen = 13-s.size();
    for(int i=1;i<=appen;i++)
        s = '0'+s;
    return s;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char a[500],b[500],o[5];
    int t,r;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%s%s%s",a,o,b);
        int dec_a = Decimal(a);
        int dec_b = Decimal(b);

        string A = convert_binary(dec_a);
        string B = convert_binary(dec_b);

        (o[0]=='+') ? r= dec_a + dec_b : r = dec_a - dec_b;

        printf("%s %c %s = %d\n",A.c_str(),o[0],B.c_str(),r);

    }
    return 0;
}
