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

int digit[10001][10];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    char temp[100];

    for(int i=1;i<=10000;i++)
    {
        sprintf(temp,"%d", i);

        for(int j=0;j<10;j++)
            digit[i][j]=digit[i-1][j];

        for(int j=0;temp[j];j++)
            digit[i][temp[j]-48]++;
    }

    int t,n;

    scanf("%d",&t);

    while(t--)
    {
        sif(n);
        for(int i=0;i<9;i++)
            printf("%d ",digit[n][i]);
        printf("%d\n",digit[n][9]);
    }
    return 0;
}
