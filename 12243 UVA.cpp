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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char str[5000];

    while(1)
    {
        gets(str);

        if(str[0]=='*')
            break;

        bool tat=true;
        int len = strlen(str)-1;
        char chk = tolower(str[0]);

        for(int i=1;i<len;i++)
            if(str[i]==32&&chk!=tolower(str[i+1]))
            {
                tat=false;
                break;
            }

        if(tat)
            pf("Y\n");
        else
            pf("N\n");
    }

    return 0;
}
