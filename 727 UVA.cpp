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

int precedence(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

void infix_to_postfix(string exp)
{
    string postfix;
    stack<char>s;

    for(int i=0;exp[i];++i)
    {
        if(isdigit(exp[i]))
            postfix.push_back(exp[i]);
        else if(exp[i]=='(')
            s.push(exp[i]);
        else if(exp[i]==')')
        {
            while(s.size() and s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            if(s.size())
            {
                if(s.top()=='(')
                    s.pop();
            }
        }
        else
        {
            while(s.size() and precedence(exp[i])<=precedence(s.top()))
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }
    while(s.size())
    {
        postfix+=s.top();
        s.pop();
    }
    cout<<postfix<<endl;

}
int main()
{
     //freopen("in.txt","r", stdin);
     //freopen("out.txt","w", stdout);

     int t,kase=0;
     string token,exp;

     scanf("%d",&t);
     cin.ignore();
     cin.ignore();

     while(t--)
     {
         kase++;
         if(kase>1)     cout<<endl;
         while(get_stl(token))
         {
             if(!token[0]||!cin)     break;
             exp+=token[0];
         }
         infix_to_postfix(exp);
         exp.clear();
     }
     return 0;
 }
