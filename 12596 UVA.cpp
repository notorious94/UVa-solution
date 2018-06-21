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

string keypad[26];
ll DP[26][21];

string get_word(int n)
{
    if(n>=0&&n<=2)    return "TWO";
    if(n>=3&&n<=5)    return "THREE";
    if(n>=6&&n<=8)    return "FOUR";
    if(n>=9&&n<=11)   return "FIVE";
    if(n>=12&&n<=14)  return "SIX";
    if(n>=15&&n<=18)  return "SEVEN";
    if(n>=19&&n<=21)  return "EIGHT";
    return "NINE";
}

ll step_size(char C,int step)
{
    if(!step)   return 1;
    if(DP[C-'A'][step]!=-1) return DP[C-'A'][step];
    ll res = 0;
    for (int i=0;i<keypad[C-'A'].size();i++)
        res += step_size(keypad[C-'A'][i],step-1);
    DP[C-'A'][step] = res;
}

void pre_calculate()
{
    for(int i=0;i<26;i++)
        keypad[i] = get_word(i);

    mem(DP,-1);

    for (int i=0;i<26;i++)
        for (int j=0;j<21;j++)
            step_size(i+'A',j);
}

char get_char(string word,int step,int k)
{
    if(!step) return word[k-1];
    for(int i=0;i<word.size();i++)
    {
        if(k<=DP[word[i]-'A'][step])
            return get_char(keypad[word[i]-'A'],step-1,k);
        k -= DP[word[i]-'A'][step];
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    pre_calculate();
    string word;
    int test,n,k;
    scanf("%d",&test);
    for(int kase = 1;kase<=test;kase++)
    {
        cin>>word>>n>>k;
        printf("Case %d: %c\n",kase,get_char(word,n,k));
    }
    return 0;
}
