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

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t,T;
    char s[MAX];
    sf("%d", &T);

    for(int kase =1 ;kase<=T;kase++)
    {
        sif(t);
        pf("Case %d:\n",kase);
        getc(stdin);
        while(t--)
        {
            gets(s);

            int Len = strlen(s);

            for(int i=0;s[i]!=0;)
            {
                if(s[i]!=32)
                {
                    pf("%c",s[i]);
                    i++;
                }

                else if(s[i] == ' ' && s[i + 1] != ' ' && i != Len - 1) {
                    putchar(s[i]);
                    i++;
                }

                else if(s[i]==32)
                {
                    pf(" ");

                    while(s[i]==32)
                        i++;

                }
            }
            cout<<endl;
        }
        if(kase!=T)
            cout<<endl;
    }

    return 0;
}
