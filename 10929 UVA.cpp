#include<bits/stdc++.h>
using namespace std;
bool div(string n)
{
    int x=0;
    for(int i=0;n[i]!='\0';i++)
    {
        x=x*10+n[i]-'0';
        x%=11;
    }
    if(x==0)
        return true;
    else
        return false;
}
int main()
{
    string n;
    while(cin>>n)
    {
        if(n=="0")
            break;

        else if(div(n))
        {
            cout<<n;
            printf(" is a multiple of 11.\n");
        }
        else
        {
            cout<<n;
            printf(" is not a multiple of 11.\n");
        }

    }
    return 0;
}
