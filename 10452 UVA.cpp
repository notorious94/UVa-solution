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
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int dx[]= {0,-1,0};
int dy[]= {1,0,-1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

vector<string>stone;
string C = "IEHOVA";
string command[3] = {"right","forth","left"};
vector<int>path;

bool inBound(int r, int c, int x, int y)
{
    return (x>=0 && x<r && y>=0 && y<c) ? true : false;
}

void input(int r)
{
    path.clear();
    stone.clear();
    char t[10];
    for(int i=0; i<r; i++)
    {
        scanf("%s",t);
        stone.push_back(t);
    }
}

void Find(int r,int c,int x,int y)
{
    int p=0;
    bool dest = false;
    while(!dest)
    {
        for(int i=0; i<3; i++)
        {
            int ux = x + dx[i];
            int vy = y + dy[i];
            if(inBound(r,c,ux,vy))
            {
                if(stone[ux][vy]=='#'&&p>=6)
                {
                    path.push_back(i);
                    dest = true;
                    break;
                }
                if(stone[ux][vy]==C[p])
                {
                    p++;
                    x = ux;
                    y = vy;
                    path.push_back(i);
                }
            }
        }
    }
}

void printSolution()
{
    for(int i=0; i<path.size()-1; i++)
            printf("%s ",command[path[i]].c_str());
        printf("%s\n",command[path.back()].c_str());
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,r,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&r,&c);
        input(r);
        int x = r-1,y;
        for(int i=0; stone[r-1][i]; i++)
            if(stone[r-1][i]=='@')
            {
                y = i;
                break;
            }
        Find(r,c,x,y);
        printSolution();
    }

    return 0;
}

