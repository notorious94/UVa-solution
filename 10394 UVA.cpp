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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count=0,n;

    int size = 20000001, root= sqrt(size);
    vector<bool>prime(20000001, true);
    vector<int>pair1;
    vector<int>pair2;

    prime[0]=prime[1]=false;
    for(int i=2;i<size;i+=2)
        prime[i]=false;

    for(int i=3;i<=root;i+=2)
        if(prime[i])
            for(int j=i*i;j<size;j+=2*i)
                prime[j]=false;

    for(int i=3;count<100000;i+=2)
        if(prime[i]&&prime[i+2])
            {
                pair1.push_back(i);
                pair2.push_back(i+2);
                count++;
            }

    prime.clear();

    while(sif(n)!=EOF)
        pf("(%d, %d)\n", pair1[n-1], pair2[n-1]);
    return 0;
}
