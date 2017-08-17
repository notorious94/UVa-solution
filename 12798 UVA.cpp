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

    int n,m,score,count,player;

    while(sf("%d%d",&n,&m)!=EOF)
    {
        player=0;
        for(int j=0;j<n;j++)
        {
            count=0;
            for(int i=0;i<m;i++)
            {
                sif(score);
                if(score>0)
                    count++;
            }
            if(count==m)
                player++;
        }
        pif(player);
    }

    return 0;
}
