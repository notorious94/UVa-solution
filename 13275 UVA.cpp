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

typedef long long ll;
typedef unsigned long long ull;

bool isLeapYear(int year)
{
    if (year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int d,m,y1,y2;
    int test;

    cin>>test;

    for(int kase = 1 ;kase <= test;kase++)
    {
        cin>>d>>m>>y1>>y2;

        pf("Case %d: ",kase);

        if(d==29 && m==2)
        {
            int b = 0;
            for(int y = y1+4;y<=y2;y+=4)
                if(isLeapYear(y))
                    b++;
            cout<<b<<endl;
        }

        else{
            int b = y2-y1;
            cout<<b<<endl;
        }

    }

    return 0;
}
