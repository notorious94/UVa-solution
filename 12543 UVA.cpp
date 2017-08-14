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

string process(string s);

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s[300000],ans;
    int i=0,max=-1;

    while(1)
    {
        cin>>s[i];
        if(s[i]=="E-N-D")
            break;
        s[i]=process(s[i]);
        int size=s[i].size();
        if(size>max)
        {
            max=size;
            ans=s[i];
        }
        ++i;
    }
    for(int i=0;i<ans.size();i++)
        pf("%c",tolower(ans[i]));
    pf("\n");
    return 0;
}
string process(string s)
{
    while(1)
    {
        if(isalpha(s[0])||s[0]=='-'||s.size()==0)
            break;
        s.erase(s.begin());
    }

    while(1)
    {
        if(s.size()==0)
            break;
        else if(isalpha(s[s.size()-1])||s[s.size()-1]=='-')
            break;
        s.erase(s.end()-1);
    }
    return s;
}
