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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

void fastScan(int &number)
{
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }

    for (; (c > 47 && c < 58); c = getchar())
        number = number *10 + c - 48;

    if (negative)
        number *= -1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(1)
    {
        fastScan(n);

        if(!n)
            break;

        switch(n)
        {
            case 561:
            case 1105:
            case 1729:
            case 2465:
            case 2821:
            case 6601:
            case 8911:
            case 10585:
            case 15841:
            case 29341:
            case 41041:
            case 46657:
            case 52633:
            case 62745:
            case 63973:
                printf("The number %d is a Carmichael number.\n", n);
                break;
            default :
                printf("%d is normal.\n",n);
                break;
        }
    }

    return 0;
}
