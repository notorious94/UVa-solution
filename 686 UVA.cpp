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

vector<bool>prime(32768,true);
vector<int>P;

void sieve()
{
    int s=32768,r=sqrt(s);

    P.push_back(2);

    for(int i=4;i<s;i+=2)
        prime[i]=false;

    for(int i=3;i<=r;i+=2)
        if(prime[i])
            for(int j=i*i;j<s;j+=i*2)
                prime[j]=false;

    for(int i=3;i<s;i+=2)
        if(prime[i])
            P.push_back(i);
    return;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    int combination[32768];

    for(int i=4;i<=32766;i+=2)
    {
        int c=0;
        for(int j=0;P[j]<=i/2;j++)
        {
            int diff = i-P[j];

            if(prime[diff])
                c++;
        }
        combination[i]=c;
    }
    int n;

    while(scanf("%d",&n))
    {
        if(!n)  break;
        printf("%d\n",combination[n]);
    }

    return 0;
}
