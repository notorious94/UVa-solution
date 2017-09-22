#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 100000
#define INF 99999
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

    list<char>beiju;
    list<char>::iterator it;

    char b[MAX+1];
    while(sf("%s", &b)!=EOF)
    {
        beiju.clear();
        it = beiju.end();

        for(int i=0;b[i]!=0;i++)
        {
            if(b[i]=='['){
                it = beiju.begin();
                continue;
            }

            else if(b[i]==']'){
                it = beiju.end();
                continue;
            }

            else
                beiju.insert(it,b[i]);
        }

        for(it = beiju.begin();it!=beiju.end();it++)
            cout<<*it;

        cout<<endl;
    }

    return 0;
}
