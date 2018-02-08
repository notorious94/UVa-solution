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

bool prime[35];

void sieve()
{
    mem(prime,true);
    int r = sqrt(35);

    for(int i=4;i<35;i+=2)
        prime[i] = false;

    for(int i=3;i<=r;i+=2)
        if(prime[i])
            for(int j=i*i;j<35;j+=i*2)
                prime[j] = false;
}

bool at[17] ={false};
vector<int>t;
int n;

void backtracking()
{
    if(t.size()==n && t.size()!= 1 && prime[t.back()+t[0]])
    {
        for(int i=0;i<n-1;i++)
            pf("%d ",t[i]);
        pif(t.back());
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(at[i]==false)
        {
            if(prime[i+t.back()])
            {
                at[i] = true;
                t.push_back(i);
                backtracking();
                at[i] = false;
                t.pop_back();
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int kase = 0;
    while(sf("%d",&n)==1)
    {
        if(++kase>1)    pf("\n");
        t.clear();
        t.push_back(1);
        pf("Case %d:\n",kase);
        if(n==1)    pf("1\n");
        else if(n%2==0)  backtracking();
    }
    return 0;
}
