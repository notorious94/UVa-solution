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

    vector<int>number;

    int i=1,n,a,b;

    while(sif(n)!=EOF)
    {
        number.push_back(n);
        sort(number.begin(), number.end());

        if(i&1)
            pf("%d\n",number.at((i-1)/2));
        else
        {
            a=i/2-1;
            b=a+1;
            pf("%d\n",(number.at(a)+number.at(b))/2);
        }
        i++;
    }
    return 0;
}
