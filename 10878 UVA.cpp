#include<bits/stdc++.h>
using namespace std;

bool cal(char ex[])
{

    char a[10],b[10], c[10];
    int i, j;
    for(i=0;;i++)
    {
        if(ex[i]=='+'||ex[i]=='-')
            break;
        a[i]=ex[i];
    }
    a[i]='\0';

    char x=ex[i];

    for(i++,j=0;;j++,i++)
    {
        if(ex[i]=='=')
            break;
        b[j]=ex[i];
    }
    b[j]='\0';

    for(i++,j=0;ex[i]!='\0';j++,i++)
        c[j]=ex[i];
    c[j]='\0';

    if(x=='+'&&atoi(a)+atoi(b)==atoi(c))
        return true;
    else if(x=='-'&&atoi(a)-atoi(b)==atoi(c))
        return true;
    else
        return false;
}
int main()
{
    char ex[50000];
    int count=0;
    while(scanf("%s", &ex)!=EOF)
    {
        if(ex[strlen(ex)-1]=='?')
            continue;
        if(cal(ex))
            count++;
    }

    cout<<count<<endl;
    return 0;
}
