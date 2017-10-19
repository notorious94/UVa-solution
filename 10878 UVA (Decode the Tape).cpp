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

void ascii(string s)
{
    int power = s.size()-1;
    int dec = 0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='1')   dec+=ceil(pow(2,power));
        power--;
    }
    printf("%c",dec);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    char c[500];

    while(gets(c))
    {
        bool f = false;
        for(int i=0;c[i];i++)
        {
            if(c[i]=='o'||c[i]==32)
            {
                if(f==false and c[i]=='o')
                {
                    s.push_back('1');
                    f=true;
                    continue;
                }
                if(f)
                {
                    if(c[i]==32)    s.push_back('0');
                    else    s.push_back('1');
                }
            }
        }
        if(s.size())    ascii(s);
        s.clear();
    }
    return 0;
}
