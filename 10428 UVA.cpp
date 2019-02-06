#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};

vector<double>a[2],b[2];

double fX(double x0)
{
    int n = a[0].size()-1;
    double r = a[0][n];
    for(int i=n-1;i>=0;i--)
        r = r*x0 + a[0][i];
    return r;
}

double dX(double x0)
{
    int n = a[1].size()-1;
    double r = a[1][n];
    for(int i=n-1;i>=0;i--)
        r = r*x0 + a[1][i];
    return r;
}

double newton_raphson(double x)
{
    double h;
    int cnt = 0;
    h = fX(x)/dX(x);
    while(fabs(h)>1e-10)
    {
        if(++cnt==101)  return x;
        x -= h;
        h = fX(x)/dX(x);
    }
    return x;
}
vector<double>roots;

void deflate(int n)
{
    roots.push_back(newton_raphson(0));

    while(roots.size()<n)
    {
        b[0].clear();
        b[1].clear();
        b[0].resize(a[0].size());

        int N = a[0].size()-1;

        double x = roots.back();

        b[0][N] = 0;

        for(int i=N-1;i>=0;i--)
            b[0][i] = b[0][i+1]*x + a[0][i+1];

        b[0].pop_back();

        for(int i=b[0].size()-1;i>0;i--)
            b[1].push_back(b[0][i]*i);

        reverse(b[1].begin(),b[1].end());

        a[0].clear();
        a[1].clear();
        a[0] = b[0];
        a[1] = b[1];

        roots.push_back(newton_raphson(x));

    }
    sort(roots.begin(),roots.end());
    for(int i=0;i<n;i++)
        printf(" %0.4lf",roots[i]);
    puts("");
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,k=1;
    double x;
    while(cin>>n)
    {
        if(!n)    break;
        a[0].clear();
        a[1].clear();
        roots.clear();

        for(int i=0;i<=n;i++)
        {
            cin>>x;
            a[0].push_back(x);
        }

        reverse(a[0].begin(),a[0].end());

        for(int i=n;i>0;i--)
            a[1].push_back(a[0][i]*i);

        reverse(a[1].begin(),a[1].end());
        printf("Equation %d:",k++);
        deflate(n);
    }
    return 0;
}

