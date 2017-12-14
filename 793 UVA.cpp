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

int Parent[1000001], Rank[1000001];
int Find(int a)
{
    return (Parent[a]==a) ? a : Parent[a] = Find(Parent[a]);
}
void makeUnion(int a, int b)
{
    int u = Find(a);
    int v = Find(b);

    if(u==v)    return;

    if(Rank[u]>Rank[v]) Parent[v] = u;
    else    Parent[u] = v;

    if(Rank[u]==Rank[v])    ++Rank[v];
    return;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    string s;

    int t,n,a,b;

    cin>>t;

    cin.ignore();
    cin.ignore();

    while(t--)
    {
        int right = 0, wrong = 0;
        bool firstLine = true;

        while(true)
        {
            get_stl(s);

            if(!s[0]||!cin)
                break;

            if(firstLine)
            {
                n = atoi(s.c_str());
                firstLine = false;
                for(int i=1;i<=n;i++){
                    Rank[i] = 1;
                    Parent[i]=i;
                }
                continue;
            }

            string temp;

            for(int i=2;i<s.size();i++)
            {
                if(s[i]==32){
                    a = atoi(temp.c_str());
                    temp.clear();
                    continue;
                }
                temp+=s[i];
            }

            b = atoi(temp.c_str());
            temp.clear();

            if(s[0]=='q')
            {
                if(Find(a)!=Find(b))    wrong++;
                else   right++;
            }

            else
                makeUnion(a,b);
        }
        pf("%d,%d\n",right,wrong);
        if(t)   cout<<endl;
    }
    return 0;
}
