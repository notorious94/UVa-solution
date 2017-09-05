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
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char sentence[MAX];
    int test;
    sif(test);
    getc(stdin);

    for(int case_id =1 ;case_id<=test;case_id++)
    {
        gets(sentence);
        pf("Case #%d:\n",case_id);

        string result;

        for(int i=0;sentence[i]!=0;i++)
            if(isalpha(sentence[i]))
                result.push_back(sentence[i]);

        int size = result.size();
        int r = sqrt(size);
        if(r*r!=size)
        {
            pf("No magic :(\n");
            continue;
        }
        int limit = size/2;
        bool palindrome = true;
        for(int i=0,j=size-1;i<limit;i++,j--)
            if(result[i]!=result[j])
            {
                palindrome = false;
                break;
            }
        if(palindrome)
            pif(r);
        else
            pf("No magic :(\n");
    }

    return 0;
}
