#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a,b,c;

    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        double s = (a+b+c)/2.0;
        double A = sqrt(s*(s-a)*(s-b)*(s-c));
        double r = (2.0*A)/(a+b+c);

        double arear_of_inner_circle = pi*r*r;
        double area_of_the_triangle = A - arear_of_inner_circle;
        double R = (a*b*c)/sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a));
        double arera_of_big_triangle = pi*R*R-A;

        printf("%.4lf ",arera_of_big_triangle);
        printf("%.4lf ",area_of_the_triangle);
        printf("%.4lf\n",arear_of_inner_circle);

    }
    return 0;
}
