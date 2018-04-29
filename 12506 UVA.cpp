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
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

char name[1000005];
int ans;

struct node
{
    int prefix;
    node *next[27];
    node()
    {
        prefix = 0;
        for(int i=0;i<27;i++)
            next[i] = NULL;
    }

}*root;

void insert_name(char n[])
{
    int level = 0;
    bool f = true;
    node *c=root;
    for(int i=0;n[i];i++)
    {
        int id = n[i] - 'a';
        if(c->next[id]==NULL)
            c->next[id] = new node();
        c = c->next[id];
        level++;
        c->prefix++;
        if(f&&c->prefix==1)
        {
            ans+=level;
            f = false;
        }
        if(c->prefix==2)
            ans++;
    }
}

void del(node *r)
{
    for(int i=0;i<27;i++)
        if(r->next[i])
            del(r->next[i]);
    delete(r);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        root = new node();
        ans = 0;
        while(n--)
        {
            scanf("%s",name);
            insert_name(name);
        }
        pif(ans);
        del(root);
    }
    return 0;
}
