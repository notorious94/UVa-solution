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

    string str, real, key;
    stringstream ss;

    map<string, string>conversation;
    map<string, string>::iterator it;

    while(getline(cin, str) && str.size())
    {
        ss.clear();
        ss << str;
        ss >> real;
        ss >> key;
        conversation[key]=real;
    }

    while(cin >> key)
    {
        it=conversation.find(key);
        if(it != conversation.end())
            pf("%s\n", it->second.c_str());
        else pf("eh\n");
    }
    return 0;
}
