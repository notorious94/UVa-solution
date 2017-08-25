#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    char text[135];
    //int case_no=0;

    while(gets(text))
    {
        if (text[0] == '\0') {
            printf("\n");
            continue;
        }

        int len = strlen(text);

        for(int i=0;text[i]!=0;i++)
        {
            if(text[i]=='!')
                pf("\n");

            else if(isdigit(text[i]))
            {
                int f=text[i]-48;
                char c=NULL;
                int j=i+1;

                while(1)
                {
                    if(isalpha(text[j])||text[j]=='*')
                    {
                        c=text[j];
                        break;
                    }
                    else if(j>=len)
                        break;
                    j++;
                }

                if(c!='b')
                    for(int a =1;a<=f;a++)
                        pf("%c",c);

                else if(c=='b')
                    for(int a =1;a<=f;a++)
                        pf(" ");
            }
        }
        pf("\n");
    }
    return 0;
}
