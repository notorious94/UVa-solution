#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char s[100000];
    while(scanf("%s", &s)!=EOF)
    {
        for(int i=0;s[i]!='\0';i++)
            printf("%c",s[i]-7);
        printf("\n");
    }
    return 0;
}
