#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
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

    string input;

    int i=1;
    while(1)
    {
        getline(cin,input);
        if(input[0]=='#')
            break;
        pf("Case %d: ",i);
        if(input=="HELLO")
            pf("ENGLISH\n");
        else if(input=="HOLA")
            pf("SPANISH\n");
        else if(input=="HALLO")
            pf("GERMAN\n");
        else if(input=="CIAO")
            pf("ITALIAN\n");
        else if(input=="ZDRAVSTVUJTE")
            pf("RUSSIAN\n");
        else if(input=="BONJOUR")
            pf("FRENCH\n");
        else
            pf("UNKNOWN\n");
        ++i;

    }
    return 0;
}
