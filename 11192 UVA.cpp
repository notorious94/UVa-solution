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

    int n, count;
    string rev;
    char s[500];

    while(1)
    {
        sf("%d%s",&n,s);

        if(n==0)
            break;

        n=strlen(s)/n;

        count=0;

        for(int i=0;s[i]!=0;i++)
        {
            if(count==n)
            {
                reverse(rev.begin(), rev.end());
                pf("%s",rev.c_str());
                count=0;
                rev.clear();
            }
            rev.push_back(s[i]);
            ++count;
        }
        reverse(rev.begin(), rev.end());
        pf("%s",rev.c_str());
        pf("\n");
        rev.clear();
    }
    return 0;
}
