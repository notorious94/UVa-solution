#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    string counter ="12312312312312312341231234";

    int test,kase,sum;

    sf("%d",&test);
    getc(stdin);

    for(int kase=1;kase<=test;kase++)
    {
        char sms[5000];
        gets(sms);
        sum=0;
        pf("Case #%d: ",kase);
        for(int i=0;sms[i]!=0;i++)
        {
            if(sms[i]==32)
                sum+=1;
            else
                sum+=counter[sms[i]-'a']-48;
        }
        pif(sum);
    }

    return 0;
}
