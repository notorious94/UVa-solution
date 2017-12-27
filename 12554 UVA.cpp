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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    string song[16];
    string name[101];

    song[0] =  "Happy";
    song[1] =  "birthday";
    song[2] =  "to";
    song[3] =  "you";

    song[4] =  "Happy";
    song[5] =  "birthday";
    song[6] =  "to";
    song[7] =  "you";

    song[8] =  "Happy";
    song[9] =  "birthday";
    song[10] =  "to";
    song[11] =  "Rujia";

    song[12] =  "Happy";
    song[13] =  "birthday";
    song[14] =  "to";
    song[15] =  "you";

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        cin>>name[i];

    bool nr=false,sr= false;
    for(int i = 1,j=0;;i++,j++)
    {
        if(i>n)
            i = 1;
        if(j==16)
            j = 0;
        pf("%s: %s\n",name[i].c_str(),song[j].c_str());
        if(i==n)    nr = true;
        if(nr==true&&j==15) break;
    }

    return 0;
}
