#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    string s,t,temp;
    int i,j;
    while(cin>>s>>t)
    {
        for(i=0,j=0;t[j]!='\0';j++)
            if(s[i]==t[j])
            {
                temp.push_back(t[j]);
                i++;
            }
        if(temp!=s)
            printf("No\n");
        else
            printf("Yes\n");
        temp.clear();
    }
    return 0;
}
