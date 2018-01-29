#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
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

ull MOD;

void power(ull F[2][2], ull n);
void multiply(ull A[2][2],ull B[2][2]);

ull Fibonacci(ull n)
{
    if(!n)           return 0%MOD;
    else if(n==1)    return 1%MOD;

    ull F[2][2] = {{1,1},
                   {1,0}};
    power(F,n-1);
    return F[0][0];
}

void power(ull F[2][2], ull n)
{
    if( n == 0 || n == 1)   return;
    ull M[2][2] = {{1,1},
                   {1,0}};
    power(F, n/2);
    multiply(F,F);
    if (n%2 != 0)   multiply(F,M);
}

void multiply(ull A[2][2],ull B[2][2])
{
    ull C[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++){
            C[i][j] = 0;
            for (int k = 0; k < 2; k++){
                C[i][j] += A[i][k]%MOD*B[k][j]%MOD;
                C[i][j] %= MOD;
            }
        }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            A[i][j] = C[i][j];
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ull n,m;

    while(scanf("%llu%llu",&n,&m)==2)
    {
        MOD = 1;
        for(int i=1;i<=m;i++)   MOD *= 2;
        pf("%llu\n",Fibonacci(n));
    }

    return 0;
}
