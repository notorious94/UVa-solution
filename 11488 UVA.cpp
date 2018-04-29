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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

int lcp;

struct node
{
    int prefix;
    node *next[2];
    node()
    {
        prefix = 0;
        next[0] = next[1] = NULL;
    }
}*root;

void insert_word(char s[])
{
    node *c = root;
    int len = 0;
    for(int i=0;s[i];i++)
    {
        int id = s[i]-'0';
        if(c->next[id]==NULL)
            c->next[id] = new node();
        c = c->next[id];
        lcp = max(lcp,++len*++c->prefix);
    }
}

void del(node *c)
{
    for(int i=0;i<2;i++)
        if(c->next[i])
            del(c->next[i]);
    delete(c);
}

int main()
{

    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    char binary[205];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        root = new node();
        lcp = 0;
        while(n--)
        {
            scanf("%s",binary);
            insert_word(binary);
        }
        pif(lcp);
        del(root);
    }
    return 0;
}
