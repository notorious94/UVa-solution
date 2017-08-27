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

    set<string>dictionary;
    set<string>::iterator it;
    string word;
    char sentence[500];

    while(gets(sentence))
    {
        for(int i=0;sentence[i]!=0;i++)
        {
            if(isalpha(sentence[i])==false)
                sentence[i]=32;

            if(isalpha(sentence[i]))
                word += tolower(sentence[i]);

            else if(sentence[i]==32)
            {
                dictionary.insert(word);
                word.clear();
            }
        }

        if(!word.empty())
            dictionary.insert(word);

        word.clear();
    }

    it=dictionary.begin();

    dictionary.erase(it);

    for(it=dictionary.begin();it!=dictionary.end();it++)
        cout<<*it<<endl;

    return 0;
}
