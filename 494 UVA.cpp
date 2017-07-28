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

    string s,r;

    while(getline(cin,s))
    {
        for(int i=0;s[i]!=0;i++)
        {
            if(isalpha(s[i]))
                r.push_back(s[i]);
            else
                r.push_back(32);
        }

        for(int i=0;;i++)
            if(isalpha(r[i]))
            {
                r.erase(r.begin(),r.begin()+i);
                break;
            }

        int word=1;
        for(int i=1;i<r.size()-1;i++)
            if(r[i]==32&&isalpha(r[i+1]))
                word++;

        pif(word);
        r.clear();
    }
    return 0;
}
