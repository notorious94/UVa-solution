#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char word[20];
    int i=0;
    while(1)
    {
        scanf("%s", word);
        i++;
        if(word[0]=='*')
            break;
        else if(word[0]=='U')
            printf("Case %d: Hajj-e-Asghar\n",i);
        else
            printf("Case %d: Hajj-e-Akbar\n",i);
    }
    return 0;
}
