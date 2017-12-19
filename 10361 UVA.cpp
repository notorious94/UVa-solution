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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char l2[MAX*2],c;
    int t;
    scanf("%d\n",&t);

    while(t--)
    {
        string l1,s1,s2,s3,s4,s5;
        while(1) /// Input Starts Here
        {
            scanf("%c",&c);
            if(c=='<')  break;
            s1.push_back(c);
        }
        while(1)
        {
            scanf("%c",&c);
            if(c=='>')  break;
            s2.push_back(c);
        }

        while(1)
        {
            scanf("%c",&c);
            if(c=='<')  break;
            s3.push_back(c);
        }

        while(1)
        {
            scanf("%c",&c);
            if(c=='>')  break;
            s4.push_back(c);
        }
        while(1)
        {
            scanf("%c",&c);
            if(c=='\n')  break;
            s5.push_back(c);
        }

        gets(l2); /// Input Ends Here

        l1 = s1 + s2 + s3 + s4 + s5;

        pf("%s\n",l1.c_str()); /// Line 1 Print

        int limit = strlen(l2) - 3;

        for(int i=0;i<limit;i++)
            pf("%c",l2[i]);
        l1 = s4+s3+s2+s5;
        pf("%s\n",l1.c_str()); /// Line 2 Print
    }
    return 0;
}
