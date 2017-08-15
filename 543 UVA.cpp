#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,ans_a,ans_b;
    int size=1000001;

    vector<bool>prime(1000001,true);

    prime[0]=prime[1]=false;

    for(int i=2;i<size;i+=2)
        prime[i]=false;

    int r=sqrt(size);

    for(int i=3;i<=r;i+=2)
        if(prime[i])
            for(int j=i*i;j<size;j+=2*i)
                prime[j]=false;

    int n;
    while(sif(n))
    {
        if(n==0)
            break;
        bool found=false;

        for(int i=3;;i+=2)
        {
            a=i;
            b=n-i;
            if(b-a<0)
                break;

            if(prime[a]&&prime[b])
            {
                found=true;
                ans_a=a;
                ans_b=b;
                break;
            }
        }
        if(found)
            pf("%d = %d + %d\n",n,ans_a,ans_b);
        else
            pf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
