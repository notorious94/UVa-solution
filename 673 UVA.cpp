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

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char>bracket;
    int n;
    scanf("%d", &n);
	  getc(stdin);
    
    while(n--)
    {
        char p[150];
        gets(p);

        for(int i=0;p[i]!=0;i++)
        {
            if(p[i]=='['||p[i]=='(')
                bracket.push(p[i]);

            else if(p[i]==']')
            {
                if(bracket.size()==0)
                {
                    bracket.push(p[i]);
                    break;
                }
                else if(bracket.top()!='[')
                {
                    bracket.push(p[i]);
                    break;
                }
                bracket.pop();
            }
            else if(p[i]==')')
            {
                if(bracket.size()==0)
                {
                    bracket.push(p[i]);
                    break;
                }
                else if(bracket.top()!='(')
                {
                    bracket.push(p[i]);
                    break;
                }
                bracket.pop();
            }
        }

        if(bracket.size()==0)
            pf("Yes\n");
        else
            pf("No\n");

        while(bracket.size()!=0)
            bracket.pop();
    }

    return 0;
}
