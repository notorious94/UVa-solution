#include<bits/stdc++.h>
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
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>coin;
    ull money [10000];
    mem(money, 0);
    money[0] = 1;

    for(int i=1;i<=21;i++)
        coin.push_back(i*i*i);

    for(int i=0;i<coin.size();i++)
        for(int j = coin[i],k=0;j<10000;j++,k++)
            money[j]+=money[k];
    int m;

    while(scanf("%d",&m)!=EOF)
        puf(money[m]);


    return 0;
}
