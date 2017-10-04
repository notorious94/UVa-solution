#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t,n;
    char s[1000005];
    char c1,c2;
    map<char,char>m;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%s%d",s,&n);

        for(int i='A';i<='Z';i++)
            m[i]=i;

        while(n--)
        {
            scanf(" %c %c",&c1,&c2);

            for(int i='A';i<='Z';i++)
                if(m[i]==c2)
                    m[i]=c1;
        }

        for(int i=0;s[i]!=0;i++)
            if(isalpha(s[i]))
                printf("%c",m[s[i]]);
            else
                printf("%c",s[i]);
        printf("\n");
        m.clear();
    }
    return 0;
}
