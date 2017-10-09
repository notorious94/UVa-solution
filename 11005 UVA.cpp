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

string digit = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<char, int>cost;

int convert(int dec, int base)
{
    if(!dec)
        return cost[digit[0]];
    int money=0;

    while(dec)
    {
        int m = dec%base;
        dec/=base;
        money += cost[digit[m]];
    }

    return money;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,q,n,c;
    vector<int>result;

    scanf("%d", &t);

    for(int kase = 1; kase<=t;kase++)
    {
        printf("Case %d:\n",kase);

        for(int i=0;digit[i];i++)
        {
            sif(c);
            cost[digit[i]]=c;
        }

        sif(q);

        while(q--)
        {
            sif(n);
            int money, min = INT_MAX;


            printf("Cheapest base(s) for number %d: ",n);

            for(int base =2 ;base<=36;base++)
            {
                money = convert(n,base);

                if(min>money)
                {
                    result.clear();
                    result.push_back(base);
                    min = money;
                }

                else if(min==money)
                    result.push_back(base);
            }

            for(int i=0;;i++)
            {

                if(i==result.size()-1)
                {
                    printf("%d\n",result[i]);
                    result.clear();
                    break;
                }
                printf("%d ",result[i]);
            }

        }
        if(kase!=t)
            printf("\n");
    }

    return 0;
}
