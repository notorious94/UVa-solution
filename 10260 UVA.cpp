#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 600
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

    const string code="01230120022455012623010202";
    string input;
    char temp;
    while(getline(cin,input))
    {
        for(int i=0;input[i]!=0;i++)
        {
            if(i==0)
            {
                if(code[input[i]-'A']!='0')
                    pf("%c",code[input[i]-'A']);
                continue;
            }
            if(code[input[i]-'A']!=code[input[i-1]-'A'])
                if(code[input[i]-'A']!='0')
                    pf("%c",code[input[i]-'A']);
        }
        pf("\n");
    }
    return 0;
}
