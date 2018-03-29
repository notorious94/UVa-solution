#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
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

class triple
{
public:
    int x,h;
    char c;
    triple(int a, int b,char f)
    {
        x = a;
        h = b;
        c = f;
    }
    bool operator < (const triple &p) const
    {
        if(x!=p.x)  return x<p.x;
        if(c!=p.c || (c==p.c && c=='S'))    return h > p.h;
        return h < p.h;
    }
};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    vector<triple>coord;
    int x,y,h;

    while(cin>>x>>h>>y)
    {
        coord.push_back(triple(x,h,'S'));
        coord.push_back(triple(y,h,'E'));
    }

    sort(all(coord));

    /*for(int i=0;i<coord.size();i++)
        printf("%d %d %c\n",coord[i].x,coord[i].h,coord[i].c);*/

    multimap<int,int>result;
    multimap<int,int>::iterator it;
    vector<int>ans;
    result.insert(pii(0,0));
    for(int i=0;i<coord.size();i++)
    {
        it = result.end();
        it--;

        int prev_max = it->first;

        if(coord[i].c == 'S')
        {
            result.insert(pii(coord[i].h,0));
            it = result.end();
            it--;
            if(prev_max!=it->first)
            {
                ans.push_back(coord[i].x);
                ans.push_back(coord[i].h);
            }
        }

        else
        {
            it = result.find(coord[i].h);
            result.erase(it);
            it = result.end();
            it--;
            if(prev_max!=it->first)
            {
                ans.push_back(coord[i].x);
                ans.push_back(it->first);
            }
        }

    }

    for(int i=0;i<ans.size()-1;i++)
        printf("%d ",ans[i]);
    printf("0\n");

    return 0;
}
