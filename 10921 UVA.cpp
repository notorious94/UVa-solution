#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);
    char tn[100];
    string holder="22233344455566677778889999";

    while(gets(tn))
    {
        for(int i=0;tn[i]!='\0';i++)
        {
            if(isalpha(tn[i]))
                printf("%c",holder.at(tn[i]-'A'));
            else
                printf("%c",tn[i]);
        }
        printf("\n");
    }
    return 0;
}
