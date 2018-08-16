#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string line[9];
    line[0] = "#include<string.h>";
    line[1] = "#include<stdio.h>";
    line[2] = "int main()";
    line[3] = "{";
    line[4] = "printf(\"";
    line[5] = "printf(\"\\n\");";
    line[6] = "return 0;";
    line[7] = "}";
    string new_line = "\\n\");";
    char s[10000];
    vector<string>command;
    int n,kase = 1;
    while(scanf("%d\n",&n)==1)
    {
        command.clear();
        if(n==0)    break;
        for(int i=0;i<n;i++)
        {
            gets(s);
            command.push_back(s);
        }
        printf("Case %d:\n",kase++);
        for(int i=0;i<4;i++)
            cout<<line[i]<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<line[4];
            for(int j=0;command[i][j];j++)
            {
                if(command[i][j]==34||command[i][j]==92||command[i][j]==39)
                    printf("%c%c",(char)92,command[i][j]);
                else
                    printf("%c",command[i][j]);
            }
            cout<<new_line<<endl;
        }
        for(int i=5;i<8;i++)
            cout<<line[i]<<endl;
    }
    return 0;
}
