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

    char s[MAX];
    string temp;

    while(sf("%s",s)!=EOF)
    {
        if(s[0]==48)
            break;

        int degree = 0;


        temp = s;

        while(1)
        {
            int sum = 0;

            for(int i=0;s[i]!=0;i++)
                sum += (s[i]-48);

            if(sum%9==0)
            {
                degree++;
                sprintf(s,"%d",sum);
            }

            else
                break;

            if(strlen(s)==1)
                break;

        }

        if(degree)
            pf("%s is a multiple of 9 and has 9-degree %d.\n",temp.c_str(),degree);
        else
            pf("%s is not a multiple of 9.\n",temp.c_str());
    }

    return 0;
}
