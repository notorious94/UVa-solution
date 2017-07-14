#include<bits/stdc++.h>
using namespace std;

///Template Starts Here
#define pf printf
#define sf scanf
#define MAX 500

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char sample[MAX],temp;

    int len,i,j;

    bool palindrome,mirror;

    string Mirror="A   3  HIL JM O   2TUVWXY5 1SE Z  8 ";

    while(gets(sample))
    {
        pf("%s -- is ", sample);

        palindrome=true;
        mirror=true;
        len = strlen(sample);

        for(i=0,j=len-1;i<=len/2;i++,j--) /// Checking Palindrome
            if(sample[i]!=sample[j])
            {
                palindrome=false;
                break;
            }

        for(i=0,j=len-1;j>=0;i++,j--) /// Checking Mirror
        {
            temp=sample[i];

            if(isdigit(temp))
                temp=Mirror[temp-22];

            else if(isalpha(temp))
                temp=Mirror[temp-'A'];

            if(sample[j]!=temp)
            {
                mirror=false;
                break;
            }
        }

        if(palindrome&&mirror)
            pf("a mirrored palindrome.\n\n");

        else if(mirror&&palindrome==false)
            pf("a mirrored string.\n\n");

        else if(palindrome)
            pf("a regular palindrome.\n\n");

        else
            pf("not a palindrome.\n\n");
    }
    return 0;
}
