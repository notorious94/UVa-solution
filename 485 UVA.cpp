#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

string sum(string a, string b)
{
    int x,y;
    string ans;
    for(int i=a.size()-1,j=b.size()-1,c=0;i>=0||j>=0||c;i--,j--)
    {
        (i<0) ? x=48 : x = a[i];
        (j<0) ? y=48 : y = b[j];

        c+=(x+y-96);
        if(c>9)
            ans.push_back(c%10+48);
        else
            ans.push_back(c+48);
        c/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    vector<string>up,down;
    up.push_back("1");
    up.push_back("1");
    cout<<1<<endl<<1<<" "<<1<<endl;
    for(int l = 1; l<204; l++)
    {
        down.clear();
        string s;
        for(int i=0;i<up.size()+1;i++)
        {
            if(i==0||i==up.size())
            {
                pf("1");
                down.push_back("1");
                (!i) ? pf(" ") : pf("\n");
                continue;
            }
            else{

                s = sum(up[i-1],up[i]);
                pf("%s ",s.c_str());
                down.push_back(s);
            }
        }
        up = down;
    }

    return 0;
}
