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

int n,p[26],r[26];
char s[50];

int Find(int a)
{
    return (a==p[a]) ? a : p[a] = Find(p[a]);
}
bool makePair(int a,int b)
{
    int u = Find(a);
    int v = Find(b);
    if(u!=v)
    {
        if(r[u]>=r[v])  p[v] = p[u] , r[u]+=r[v];
        else            p[u] = p[v] , r[v]+=r[u];
        return true;
    }
    return false;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    scanf("%d\n",&test);
    while(test--)
    {
        vector<pii>edge;
        while(gets(s))
        {
            if(s[0]=='*')   break;
            edge.push_back(pii(s[1]-'A',s[3]-'A'));
        }

        gets(s);
        int tree = 0,acron = 0;
        for(int i=0;i<strlen(s);i+=2)
        {
            int a = s[i]-'A';
            tree++;
            p[a] = a;
            r[a] = 1;
        }

        for(int i=0;i<edge.size();i++)
            if(makePair(edge[i].first,edge[i].second))
                tree--;

        for(int i=0;i<strlen(s);i+=2)
        {
            int a = s[i]-'A';
            if(r[Find(a)]==1)
                tree--,acron++;
        }

        printf("There are %d tree(s) and %d acorn(s).\n",tree,acron);

    }
    return 0;
}

