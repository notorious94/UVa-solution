#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n,count;
    char s[15];

    while(sf("%d%d", &n,&m)!=EOF)
    {
        count = 0;
        for(int i=n;i<=m;i++)
        {
            map<char,int>occur;
            count++;
            sprintf(s,"%d",i);

            for(int a=0;s[a]!=0;a++)
            {
                occur[s[a]]++;
                if(occur[s[a]]>1){
                    count--;
                    break;
                }
            }
        }
        cout<<count<<endl;
    }

    return 0;
}
