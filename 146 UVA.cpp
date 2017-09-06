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

    string code;

    while(cin>>code)
    {
        if(code[0]=='#')
            break;

        bool next = next_permutation(code.begin(),code.end());

        if(next)
            cout<<code<<endl;
        else
            cout<<"No Successor"<<endl;
    }

    return 0;
}
