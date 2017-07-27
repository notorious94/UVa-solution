#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 600
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
    int n,k=0;
    while(1)
    {
        sif(n);

        if(n==0)
            break;
        k++;
        if(k>1)
            pf("\n");

        vector<int>data(n,0);

        for(int i=0;i<n;i++)
            sif(data[i]);

        for(int a=0;a<n;a++)
            for(int b=a+1;b<n;b++)
                for(int c=b+1;c<n;c++)
                    for(int d=c+1;d<n;d++)
                        for(int e=d+1;e<n;e++)
                            for(int f=e+1;f<n;f++)
                                pf("%d %d %d %d %d %d\n",data[a],data[b],data[c],data[d],data[e],data[f]);
        data.clear();

    }
    return 0;
}
