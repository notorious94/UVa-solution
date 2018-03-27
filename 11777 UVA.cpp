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

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

char grade(double m)
{
    if(m>=90.0) return 'A';
    if(m>=80.0) return 'B';
    if(m>=70.0) return 'C';
    if(m>=60.0) return 'D';
    return 'F';
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    double t,c[3];
    scanf("%d",&test);
    for(int k=1;k<=test;k++)
    {
        double sum = 0;

        for(int i=0;i<4;i++)
        {
            scanf("%lf",&t);
            sum+=t;
        }

        for(int i=0;i<3;i++)
            scanf("%lf",&c[i]);
        sort(c,c+3);
        sum+=((c[1]+c[2])/2.0);

        printf("Case %d: %c\n",k,grade(sum));
    }
    return 0;
}

