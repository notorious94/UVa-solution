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

string digit = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; /// Holding Digits
map<char, int>cost; /// Holding Print Cost

int convert_in_all_base(int decimal, int base);

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t, q, c, n, print_cost;
    map<int, int>ans;
    vector<int>Base;

    scanf("%d", &t);/// No. of Test Cases

    for(int kase = 1; kase<=t; kase++)
    {
        printf("Case %d:\n", kase);/// Case Print

        for(int i=0;digit[i];i++) /// Adding_Cost
        {
            scanf("%d", &c);
            cost[digit[i]]=c;
        }

        scanf("%d", &q); /// Query

        while(q--)
        {
            scanf("%d",&n); /// Decimal Value

            ans.clear();
            Base.clear();

            printf("Cheapest base(s) for number %d: ", n);

            int min_cost = INT_MAX;

            for(int base = 2; base <= 36; base++)
            {
                print_cost = convert_in_all_base(n,base); /// Getting Cost for every base

                ans[base] = print_cost; /// Storing Cost

                if(min_cost>print_cost) /// Finding the minimum cost value
                    min_cost=print_cost;

            }

            for(int i=2;i<=36;i++) /// Fonding Base(s) with minimum cost
                if(ans[i]==min_cost)
                    Base.push_back(i);

            for(int i=0;i<Base.size()-1;i++) /// Printing Answer
                printf("%d ",Base[i]);

            printf("%d\n",Base[Base.size()-1]); /// Lase Answer
        }

        if(kase!=t)
            printf("\n");

    }
    return 0;
}

int convert_in_all_base(int decimal, int base)
{
    if(!decimal)
        return cost[digit[0]];

    int Cost = 0;

    while(decimal)
    {
        int m = decimal%base;
        decimal/=base;
        Cost += cost[digit[m]];
    }

    return Cost;
}
