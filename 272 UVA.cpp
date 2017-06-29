#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt","w", stdout);
    char s;
    int o=0, i;
    while(scanf("%c", &s)!=EOF)
    {
        if(s=='"')
        {
            o++;
            if(o%2!=0)
                printf("``");
            else
                printf("\'\'");
        }
        else
            printf("%c",s);
    }
    return 0;
}
