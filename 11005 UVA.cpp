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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

string digit = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; /// Holding Digits
map<char, int>cost; /// Holding Print Cost

int convert_in_all_base(int decimal, int base)
{
    int Cost = 0;
    string s;

    if(decimal==0)
        return cost[digit[0]];

    while(decimal)
    {
        int m = decimal%base;
        decimal/=base;
        //s+=digit[m];
        Cost += cost[digit[m]];
    }

    return Cost;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t, q, c, n, print_cost;
    map<int, int>ans;

    vector<int>Base;

    scanf("%d", &t);

    for(int kase =1; kase<=t;kase++)
    {
        printf("Case %d:\n",kase);/// Case Print

        for(int i=0;digit[i]!=0;i++) /// Adding_Cost
        {
            scanf("%d", &c);
            cost[digit[i]]=c;
        }

        scanf("%d",&q); /// Query

        while(q--)
        {
            scanf("%d",&n);

            ans.clear();
            Base.clear();

            printf("Cheapest base(s) for number %d: ", n);

            int min_cost = INT_MAX;

            for(int base = 2; base <= 36; base++)
            {
                print_cost = convert_in_all_base(n,base);

                ans[base] = print_cost;

                if(min_cost>print_cost)
                    min_cost=print_cost;

            }
            for(int i=2;i<=36;i++)
                if(ans[i]==min_cost)
                    Base.push_back(i);
            for(int i=0;i<Base.size()-1;i++)
                printf("%d ",Base[i]);

            printf("%d\n",Base[Base.size()-1]);
        }
        if(kase!=t)
            printf("\n");
        cost.clear();
    }
    return 0;
}
