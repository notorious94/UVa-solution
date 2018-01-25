#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 100001
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

vector<bool>prime(MAX,true);

void sieve()
{
    prime[0] = prime[1] = false;
    int r = sqrt(prime.size());

    for(int i=4;i<MAX;i+=2)
        prime[i] = false;

    for(int i=3;i<=r;i+=2)
        if(prime[i])
            for(int j=i*i; j<MAX;j+=i*2)
                prime[j] = false;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string p;
    sieve();

    char num[300];

    while(scanf("%s",num))
    {
        if(!strcmp("0",num))     break;
        int range, len = strlen(num), bigPrime = 2,number;
        for(int i=0;num[i];i++)
        {
            p.clear();
            p+=num[i];
            range = min(5,(len-(i+1)));
            for(int k = i+1,j=0;j<range;j++,k++)
            {
                p+=num[k];
                number = atoi(p.c_str());
                if(number<MAX)
                {
                    if(prime[number] && number > bigPrime)
                        bigPrime = number;
                }
            }

        }
        pf("%d\n",bigPrime);
    }
}
