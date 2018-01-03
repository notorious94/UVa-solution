#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 131071
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ULL;

ULL bigMod(ULL B, ULL P, ULL M=MOD)
{
    if (P == 0) return 1 % M;
    else if (P % 2 == 0)
    {
        ULL result = bigMod(B, P / 2, M) % M;
        return (result * result) % M;
    }
    else    return ((B % M) * (bigMod(B, P - 1, M) % M)) % M;
}

string b;

int power[10001];

void process()
{
    int r = 0;

    for(int i=0,j = b.size()-1;b[i];i++,j--)
        if(b[i]=='1')
            r = (r+= power[j])%MOD;

    (!r) ? pf("YES\n") : pf("NO\n");
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<10001;i++)
        power[i] = bigMod(2,i);

    char s[50000];

    while(gets(s))
    {
        if(s[strlen(s)-1]=='#')
        {
            s[strlen(s)-1] = 0;
            b+=s;
            process();
            b.clear();
        }
        else b+=s;
    }
    return 0;
}
