#include<bits/stdc++.h>
using namespace std;

///Template Starts Here
#define pf printf
#define sf scanf
#define MAX 600

typedef long long ll;
typedef unsigned long long ull;

bool happy(char n[])
{
    int sum;
    char temp[50];
    strcpy(temp, n);
    while(1)
    {
        sum=0;
        for(int i=0;n[i]!='\0';i++)
            sum += (n[i]-48)*(n[i]-48);
        sprintf(n,"%d",sum);
        if(strlen(n)==1||!strcmp(temp,n))
            break;
    }
    if(!strcmp(n,"1")||!strcmp(n,"7"))
        return true;
    else
        return false;
}

int main()
{

    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, c=0;
    char n[50];
    sf("%d\n", &t);

    while(t--)
    {
        c++;
        gets(n);
        pf("Case #%d: %s is ",c,n);
        if(happy(n))
            pf("a Happy number.\n");
        else
            pf("an Unhappy number.\n");
    }
    return 0;
}
