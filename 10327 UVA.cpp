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

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int data[1000];

    while(sif(n)!=EOF)
    {
        int _swap = 0;

        for(int i=0;i<n;i++)
            sif(data[i]);

        for(int i=0;i<n;i++)
        {
            int value = data[i];
            int hole = i;

            while(hole>0&&data[hole-1]>value)
            {
                data[hole] = data[hole-1];
                hole--;
                _swap++;
            }
            data[hole] = value;
        }

        pf("Minimum exchange operations : ");

        pif(_swap);

        _swap=0;
    }

    return 0;
}
