#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
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

    int day[3651];
    int a,t,sim,party,h,sum,count;
    sif(t);

    while(t--)
    {
        memset(day,0,sizeof(day));

        sum=0,count=0;

        sf("%d%d",&sim,&party);

        while(party--)
        {
            sif(h);
            a=h;
            while(a<=sim)
            {
                day[a]=1;
                a+=h;
            }
        }

        for(int i=1;i<=sim;i++)
        {
            if(count==5)
            {
                count=0;
                i++;
                continue;
            }

            if(day[i]!=0)
                ++sum;
            ++count;
        }
        pif(sum);
    }
    return 0;
}
