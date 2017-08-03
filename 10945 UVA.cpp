#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    string s,answer;
    bool pal;

    while(1)
    {
        getline(cin, s);

        if(s=="DONE")
            break;

        pal=true;

        for(int i=0;s[i]!=0;i++)
            if(isalpha(s[i]))
                answer.push_back(s[i]);

        for(int i=0, j=answer.size()-1 ; i<answer.size()/2;i++,j--)
            if(tolower(answer[i])!=tolower(answer[j]))
            {
                pal=false;
                break;
            }

        if(pal)
            pf("You won't be eaten!\n");
        else
            pf("Uh oh..\n");

        answer.clear();
    }
    return 0;
}
