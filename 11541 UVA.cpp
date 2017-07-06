#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    char temp,code[500];
    string n;
    int t,f,c=0,j,i;
    scanf("%d\n", &t);
    while(t--)
    {
        c++;
        gets(code);
        printf("Case %d: ",c);
        for(i=0;code[i]!='\0';i++)
        {
            if(isalpha(code[i]))
            {
                temp=code[i];
                i++;
                do
                {
                    n.push_back(code[i]);
                    i++;
                }while(isdigit(code[i]));
                f=atoi(n.c_str());
                for(j=1;j<=f;j++)
                    printf("%c",temp);
                n.clear();
                i--;
            }
        }
        n.clear();
        printf("\n");
    }
    return 0;
}
