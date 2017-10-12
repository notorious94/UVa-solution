#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 999999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t,r,Z,temp,n;
    int data[15];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;i++)
            scanf("%d",&data[i]);

        r = 200;
        bool L = true;

        while(r--)
        {
            int count=0;
            Z=data[0];

            for(int i=0;i<n-1;i++)
            {
                if(!i)  data[i] = abs(data[i] - data[i+1]);
                else    data[i] = abs(temp - data[i+1]);

                temp = data[i+1];

                if(!data[i])    count++;
            }

            data[n-1] = abs(data[n-1] - Z);

            if(!data[n-1])  count++;

            if(count==n)
            {
                L = false;
                break;
            }
        }

        if(!L)
            printf("ZERO\n");
        else
            printf("LOOP\n");
    }
    return 0;
}
