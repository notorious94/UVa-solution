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
#define vec vector<int>

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int test,v;
    char dump;
    string str;

    vector<int>index;
    map<int,string>p;
    map<int,string>::iterator it;

    sif(test);

    for(int kase = 1;kase <= test; kase++)
    {
        while(1)
        {
            sif(v);
            index.push_back(v);

            dump = getchar();

            if(dump=='\n')
                break;
        }

        for(int i = 0 ;i < index.size(); i++)
        {
            cin>>str;
            p[index[i]]=str;
        }

        for(it=p.begin();it!=p.end();it++)
            pf("%s\n", it->second.c_str());

        p.clear();
        index.clear();

        if(kase!=test)
            pf("\n");
    }

    return 0;
}
