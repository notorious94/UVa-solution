#include<bits/stdc++.h>
using namespace std;

///Template Starts Here
#define pf printf
#define sf scanf
#define MAX 600

typedef long long ll;
typedef unsigned long long ull;

int chk(char c[])
{
    int t=0,w=0,o=0,n=0,e=0;
    for(int i=0;c[i]!='\0';i++)
    {
        if(c[i]=='t')
            t++;
        if(c[i]=='w')
            w++;
        if(c[i]=='o')
            o++;
        if(c[i]=='n')
            n++;
        if(c[i]=='e')
            e++;
    }
    if(o>=1&&n>=1||o>=1&&e>=1||n>=1&&e>=1)
        return 1;
    else if(t>=1&&w>=1||t>=1&&o>=1||w>=1&&o>=1)
        return 2;
    else
        return 3;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    char c[200];
    scanf("%d\n", &t);

    while(t--)
    {
        gets(c);
        switch(chk(c))
        {
            case 1:
                printf("1\n");
                break;
            case 2:
                printf("2\n");
                break;
            case 3:
                printf("3\n");
                break;
        }
    }
    return 0;
}
