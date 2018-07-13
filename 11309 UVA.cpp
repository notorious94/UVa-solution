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

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};

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

bool palindrome[24][60];

bool isPalindrome(string p)
{
    for(int i=0,j=p.size()-1; i<p.size()/2; j--,i++)
        if(p[i]!=p[j])  return false;
    return true;
}

string result_set[24][60];

void dp()
{
    for(int h=0; h<24; h++)
    {
        for(int m=0; m<60; m++)
        {
            string p;
            int tmp;
            if(h>0)
            {
                tmp = h;
                string t;
                while(tmp)
                {
                    t+=((tmp%10)+48);
                    tmp/=10;
                }
                reverse(all(t));
                p+=t;
            }
            if(h>0&&m<10)   p+="0";
            if(m>0)
            {
                tmp = m;
                string t;
                while(tmp)
                {
                    t+=((tmp%10)+48);
                    tmp/=10;
                }
                reverse(all(t));
                p+=t;
            }
            palindrome[h][m] = isPalindrome(p);
        }
    }
}

string make_strng(int h,int m)
{
    string p,r;
    int t;
    t = h;
    if(h<10)    p+="0";
    if(h==0)    p+="0";
    else
    {
        while(t)
        {
            r+=((t%10)+48);
            t/=10;
        }
        reverse(all(r));
        p+=r;
    }
    p+=":";
    r.clear();
    t = m;
    if(m<10)    p+="0";
    if(m==0)    p+="0";
    else
    {
        while(t)
        {
            r+=((t%10)+48);
            t/=10;
        }
        reverse(all(r));
        p+=r;
    }
    return p;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp();
    int H=0,M=0;
    for(int i=23;i>=0;i--)
    {
        for(int j=59;j>=0;j--)
        {
            if(palindrome[i][j])
            {
                H = i;
                M = j;
            }
            result_set[i][j] = make_strng(H,M);
        }
    }
    char s[10];
    int t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        bool flag = false;
        int h=0,m=0;
        h+=(s[0]-48)*10;
        h+=(s[1]-48);
        m+=(s[3]-48)*10;
        m+=(s[4]-48);
        m++;
        if(m>=60)
        {
            m %= 60;
            h++;
            h%=24;
        }
        printf("%s\n",result_set[h][m].c_str());
    }
    return 0;
}
