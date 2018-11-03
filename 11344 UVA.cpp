#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int DP[10001][13];

ll bigmod(ll a,ll p,ll m)
{
    if(!p)  return 1%m;
    if(p&1)
        return (bigmod(a,p-1,m) * a%m)%m;
    else
    {
        ll p1 = bigmod(a,p/2,m);
        return (p1 * p1)%m;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    for(int i=1;i<13;i++)
        for(int j=0;j<=10000;j++)
            DP[j][i] = bigmod(10,j,i);

    char M[10009];
    int test,n,S[12];

    scanf("%d",&test);

    while(test--)
    {
        scanf("%s%d",M,&n);

        for(int i=0;i<n;i++)
            scanf("%d",&S[i]);

        bool wonderful = true;

        for(int i=0;i<n;i++)
        {
            int remainder = 0;
            int MOD = S[i];
            for(int j=0,p = strlen(M)-1;M[j];j++,p--)
            {
                if(M[j]!=0)
                {
                    remainder += ((M[j]-48) * DP[p][MOD])%MOD;
                    remainder%=MOD;
                }
            }
            if(remainder!=0)
            {
                wonderful = false;
                break;
            }
        }
        (wonderful) ? printf("%s - Wonderful.\n",M) : printf("%s - Simple.\n",M);
    }
    return 0;
}

