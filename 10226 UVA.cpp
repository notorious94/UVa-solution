#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t,kase=0;
    double Size;
    string s;
    map<string,double>tree;
    map<string,double>::iterator it;

    scanf("%d",&t);
    cin.ignore();
    cin.ignore();

    while(t--)
    {
        kase++;

        if(kase>1)
            cout<<endl;

        Size=0;

        while(get_stl(s))
        {
            if(!s[0]||!cin)     break;
            Size++;
            tree[s]++;
        }

        for(it = tree.begin() ;it!=tree.end();it++)
        {
            double ans=(it->second/Size)*100.0;
            printf("%s %0.4lf\n",it->first.c_str(),ans);
        }
        tree.clear();
    }

    return 0;
}
