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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    double H,U,D,F;

    while(sf("%lf%lf%lf%lf",&H,&U,&D,&F))
    {
        if(H==0)   break;

        F=(U*F)/100.0;
        double day=0, h=0;
        bool f=false;

        while(true)
        {
            day++;

            h+=U;

            if(h>H) break;

            h-=D;

            if(h<0){
                f=true;
                break;
            }

            U-=F;

            if(U<0)
                U=0.0;
        }

        if(f)
            cout<<"failure on day "<<day<<endl;
        else
            cout<<"success on day "<<day<<endl;
    }

    return 0;
}
