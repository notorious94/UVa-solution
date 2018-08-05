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

class Book
{
public:
    string title,author;
    Book(string t,string a)
    {
        title = t;
        author = a;
    }
    bool operator < (const Book &p) const
    {
        if(author!=p.author)    return author < p.author;
        return title < p.title;
    }
};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[1000];
    map<string,int>position;
    vector<Book>B;

    for(int id=0;gets(s);id++)
    {
        if(s[0]=='E')   break;
        int colon = 0,i = 0;
        string title,author;
        for(i=0;colon!=2&&s[i];i++)
        {
            if(s[i]=='\"')  colon++;
            title+=s[i];
        }
        for(i+=4;s[i];i++)  author+=s[i];
        B.push_back(Book(title,author));
    }

    sort(all(B));
    bool borrow[B.size()],returned[B.size()];

    mem(borrow,false);
    mem(returned,false);

    for(int i=0;i<B.size();i++)
        position[B[i].title] = i;

    while(gets(s))
    {
        if(s[0]=='E')   break;
        if(s[0]=='B')
        {
            int pos = position[s+7];
            borrow[pos] = true;
            returned[pos] = false;
        }
        else if(s[0]=='R')
        {
            int pos = position[s+7];
            returned[pos] = true;
        }
        else
        {
            int prev = -1;
            for(int i=0;i<B.size();i++)
            {
                if(borrow[i]==false)    prev = i;
                else if(returned[i])
                {
                    if(prev==-1)        printf("Put %s first\n",B[i].title.c_str());
                    else                printf("Put %s after %s\n",B[i].title.c_str(),B[prev].title.c_str());
                    returned[i] = false;
                    borrow[i]   = false;
                    prev = i;
                }
            }
            puts("END");
        }
    }
    return 0;
}
