#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 1001
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

char a[MAX],b[MAX];
int DP[MAX][MAX];

int LCS(int i=0, int j=0)
{
    if(!a[i]||!b[j])
        return 0;

    else if(DP[i][j]!=-1)
        return DP[i][j];

    int length=0;

    if(a[i]==b[j])
        length = 1 + LCS(i+1, j+1);
    else
        length = max(LCS(i+1,j),LCS(i,j+1));

    DP[i][j]=length;
    return length;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    while(gets(a))
    {
        memset(DP, -1, sizeof DP);
        gets(b);
        pif(LCS());
    }
    return 0;
}
