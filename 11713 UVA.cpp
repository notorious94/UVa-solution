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

bool is_vowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
    else
        return false;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    char n1[25], n2[25];
    int test;
    sif(test);

    while(test--)
    {
        sf("%s%s",n1,n2);

        int len_1 = strlen(n1);
        int len_2 = strlen(n2);

        if(len_1!=len_2)
        {
            pf("No\n");
            continue;
        }

        bool verdict = true;

        for(int i=0;n1[i]!=0;i++)
        {
            if(n1[i]!=n2[i])
            {
                if(is_vowel(n1[i])==false)
                {
                    verdict = false;
                    break;
                }
                else if(!is_vowel(n2[i]))
                {
                    verdict = false;
                    break;
                }
            }
        }

        if(verdict==true)
            pf("Yes\n");
        else
            pf("No\n");
    }

    return 0;
}
