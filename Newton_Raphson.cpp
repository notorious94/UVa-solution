#include<bits/stdc++.h>
using namespace std;

int a[100];
int _a[100];

double f_of_x(double x,int degree)
{
    double r1,r2;
    r1 = a[degree];
    for(int i=degree-1;i>=0;i--)
    {
        r2 = (r1*x) + a[i];
        r1 = r2;
    }
    return r1;
}

double f_inverse_x(double x,int degree)
{
    double r1,r2;
    r1 = _a[degree];
    for(int i=degree-1;i>0;i--)
    {
        r2 = (r1*x) + _a[i];
        r1 = r2;
    }
    return r1;
}

double newton_raphson(double x,int degree,double EPS)
{
    double x0 = x,x1;
    while(true)
    {
        double fx = f_of_x(x0,degree);
        double _fx = f_inverse_x(x0,degree);
        if(fx==0.000000)   return x0;
        x1 = x0 - (fx / _fx);
        if(fabs((x1-x0)/x1)<EPS)   return x1;
        x0 = x1;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int degree;
    double x;

    //printf("Enter the degree of equation: ");
    scanf("%d",&degree);

    printf("Enter co-efficients:\n");

    for(int i=degree;i>=0;i--)
    {
        scanf("%d",&a[i]);
        _a[i] = i*a[i];
    }

    printf("Enter Your Initial Value: ");
    scanf("%lf",&x);

    double root = newton_raphson(0,3,0.0005);
    printf("%0.6lf\n",root);

    return 0;

}
