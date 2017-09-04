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
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char in[MAX], out[MAX];
    int t;
    sif(t);
    getc(stdin);

    for(int case_id=1;case_id<=t;case_id++)
    {
        gets(in);
        gets(out);

        pf("Case %d: ",case_id);

        if(!strcmp(in,out))
        {
            pf("Yes\n");
            continue;
        }
        string input, output;

        for(int i=0;in[i]!=0;i++)
            if(in[i]!=' ')
                input+=in[i];

        for(int i=0;out[i]!=0;i++)
            if(out[i]!=' ')
                output+=out[i];

        if(input==output)
            pf("Output Format Error\n");
        else
            pf("Wrong Answer\n");
    }

    return 0;
}
