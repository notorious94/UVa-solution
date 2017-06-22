#include<bits/stdc++.h>

using namespace std;

char digit[5000];

int sum()
{
    int sum=0;
    for(int i=0;digit[i]!='\0';i++)
        sum+=(digit[i]-'0');

    sprintf(digit,"%d",sum);
    return sum;
}

int main()
{
    //freopen("d:\\in.txt", "r", stdin);
    //freopen("d:\\out.txt", "w", stdout);

    int s;

    while(scanf("%s", &digit))
    {
        if(!strcmp(digit,"0"))
            break;

        if(strlen(digit)==1)
        {
            printf("%s\n",digit);
            continue;
        }
        while(strlen(digit)>1)
            s=sum();

        printf("%d\n",s);
    }
    return 0;
}
