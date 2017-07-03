#include<bits/stdc++.h>

using namespace std;

int main()
{

    int c,i=0;
    double a,v,u,t,s;
    while(1)
    {
        i++;
        scanf("%d", &c);
        if(c==0)
            break;
        switch(c)
        {
            case 1:
                scanf("%lf%lf%lf",&u,&v,&t);
                a=(v-u)/t;
                s=u*t+(0.5*a*t*t);
                printf("Case %d: %0.3lf %0.3lf\n",i,s,a);
                break;
            case 2:
                scanf("%lf%lf%lf",&u,&v,&a);
                t=(v-u)/a;
                s=u*t+(0.5*a*t*t);
                printf("Case %d: %0.3lf %0.3lf\n",i,s,t);
                break;
            case 3:
                scanf("%lf%lf%lf",&u,&a,&s);
                v=pow((u*u+2*a*s),0.5);
                t=(v-u)/a;
                printf("Case %d: %0.3lf %0.3lf\n",i,v,t);
                break;
            case 4:
                scanf("%lf%lf%lf",&v,&a,&s);
                u=pow((v*v-2*a*s),0.5);
                t=(v-u)/a;
                printf("Case %d: %0.3lf %0.3lf\n",i,u,t);
                break;
        }
    }
    return 0;
}
