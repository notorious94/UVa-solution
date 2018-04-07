#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

class cake
{
public:
    string name;
    int budget;
    cake(string n,int b)
    {
        name = n,budget = b;
    }
    bool operator <(const cake &c) const
    {
        if(budget!=c.budget)
            return budget < c.budget;
        return name < c.name;
    }
};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int t,m,n,k,b,c;
    char binders[100005],ingrident[100005],cake_name[100005];
    scanf("%d\n",&t);
    while(t--)
    {
        gets(binders);
        for(int i=0;binders[i];i++)
            printf("%c",toupper(binders[i]));
        puts("");
        scanf("%d%d%d",&m,&n,&b);
        map<string,int>mosla;
        while(m--)
        {
            scanf("%s%d",ingrident,&c);
            mosla[ingrident] = c;
        }
        vector<cake>result;
        getc(stdin);
        while(n--)
        {
            gets(cake_name);
            scanf("%d",&k);
            int sum = 0,q;
            while(k--)
            {
                scanf("%s%d",ingrident,&q);
                sum+=mosla[ingrident]*q;
            }
            getc(stdin);
            if(sum<=b)
                result.push_back(cake(cake_name,sum));
        }
        if(result.empty())
            printf("Too expensive!\n");
        else
        {
            sort(all(result));
            for(int i=0;i<result.size();i++)
                printf("%s\n",result[i].name.c_str());
        }
        puts("");
    }
    return 0;
}
