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

struct scram
{
    string sorted;
    string real;
};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size=0;
    char word[130];
    string temp;

    scram words[5000];

    while(1)
    {
        sf("%s", word);
        if(!strcmp(word,"XXXXXX"))
            break;
        temp=word;
        sort(temp.begin(), temp.end());
        words[size].sorted=temp;
        words[size].real=word;
        ++size;
    }

    while(1)
    {
        sf("%s", word);
        if(!strcmp(word,"XXXXXX"))
            break;
        temp=word;
        sort(temp.begin(), temp.end());

        string ans[size];
        bool match=false;
        int index=0;
        for(int i=0;i<size;i++)
        {
            if(words[i].sorted==temp)
            {
                ans[index]=words[i].real;
                ++index;
                match=true;
            }
        }
        if(match)
        {
            sort(ans, ans+index);
            for(int i=0;i<index;i++)
                pf("%s\n", ans[i].c_str());
        }
        else
            pf("NOT A VALID WORD\n");
        pf("******\n");
    }

    return 0;
}
