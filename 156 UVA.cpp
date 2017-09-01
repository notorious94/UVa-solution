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

    map<string , int>f;
    map<string , int>::iterator _if;
    map<string , string>word;
    set<string>ans;
    set<string>::iterator it;

    char str[MAX];
    string temp, real;

    while(gets(str))
    {
        if(str[0]=='#')
            break;
        for(int i=0;str[i]!=0;i++)
        {
            if(str[i]==32)
            {
                sort(temp.begin(),temp.end());
                word[temp]=real;
                f[temp]++;
                temp.clear();
                real.clear();
                continue;
            }
            else if(str[i]!=32)
            {
                if(isalpha(str[i]))
                    temp.push_back(tolower(str[i]));
                real.push_back(str[i]);
            }
        }
        if(temp.size()!=0)
        {
            sort(temp.begin(),temp.end());
            word[temp]=real;
            f[temp]++;
            temp.clear();
            real.clear();
        }
    }

    for(_if=f.begin();_if != f.end();_if++)
        if(_if->second==1)
            ans.insert(word[_if->first]);

    for(it = ans.begin();it!=ans.end();it++)
        cout<<*it<<endl;

    return 0;
}
