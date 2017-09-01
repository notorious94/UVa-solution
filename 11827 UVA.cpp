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
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test,n;
    vector<int>data;

    sif(test);

    while(test--)
    {
        int max_gcd=1;
        int count=0;
        char c;
        while (true)
        {
            scanf("%d", &n);

            data.push_back(n);

            while ((c = getchar()) == ' ');
                ungetc(c, stdin);
            if (c == 10 || c == -1)
                break;
        }

        int limit=data.size();

        for(int i=0;i<limit;i++)
            for(int j=0;j<limit;j++)
                if(j!=i)
                {
                    int gcd = __gcd(data[i], data[j]);
                    if(gcd > max_gcd)
                    max_gcd = gcd;
                }

        pif(max_gcd);
        data.clear();
    }

    return 0;
}
