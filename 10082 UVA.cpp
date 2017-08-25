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

    char input[MAX];
    char MAP[] = ";    M0,.9`12345678 L -    VXSWDFGUHJKNBIO EARYCQZT P][";
    int casee=0;
    while(gets(input))
    {
        for(int i=0;input[i]!=0;i++)
            if(input[i]==32)
                pf(" ");
            else
                pf("%c",MAP[input[i]-39]);
        pf("\n");
    }
    return 0;
}
