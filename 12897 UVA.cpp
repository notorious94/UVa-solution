#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t,c;
    scanf("%d\n", &t);
    char s[1000001],r[5];
    while(t--)
    {
        gets(s);
        scanf("%d\n",&c);
        for(int i=1;i<=c;i++)
        {
            gets(r);
            for(int a=0;s[a]!='\0';a++)
                if(s[a]==r[2])
                    s[a]=r[0];
        }
        printf("%s\n",s);
    }
    return 0;
}
