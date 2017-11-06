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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s[3],m[3];
    map<char,char>route;
    char a[MAX];

    route[32] = 32;
    s[0] = "][poiuytre";
    m[0] = "poiuytrewq";
    s[1] = "\\';lkjhgfd";
    m[1] = ";lkjhgfdsa";
    s[2] = "/.,mnbvc";
    m[2] = ",mnbvcxz";

    for(int i=0;i<3;i++)
        for(int j=0;j<s[i].size();j++)
            route[s[i][j]] = m[i][j];

    while(gets(a))
    {
        for(int i=0;a[i];i++)
        {
            if(isalpha(a[i]))
                printf("%c",route[tolower(a[i])]);
            else
                printf("%c",route[a[i]]);
        }
        printf("\n");
    }

    return 0;
}
