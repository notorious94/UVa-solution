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

int s = 100000001;

vector<bool>prime(100000001,true);

void sieve()
{
    int r = sqrt(s);
    prime[1]=prime[0]=false;
    for(int i=4;i<s;i+=2)
        prime[i]=false;

    for(int i=3;i<=r;i+=2)
        if(prime[i])
            for(int j=i*i;j<s;j+=i*2)
                prime[j]=false;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    sieve();

    int n,l,d,a=0,b=0;

    while(scanf("%d",&n)!=EOF)
    {
        if(n==1)
        {
            printf("%d is not the sum of two primes!\n",n);
            continue;
        }
        if(n%2)
        {
            if(prime[n-2])  printf("%d is the sum of 2 and %d.\n",n,n-2);
            else            printf("%d is not the sum of two primes!\n",n);
            continue;
        }

        bool p = true;
        int l = n/2;

        for(int i=l;i<n;i++)
        {
            if(prime[i]&&prime[n-i]&&n-l!=i)
            {
                p=false;
                printf("%d is the sum of %d and %d.\n",n,n-i,i);
                break;
            }
        }

        if(p)  printf("%d is not the sum of two primes!\n",n);
    }
    return 0;
}
