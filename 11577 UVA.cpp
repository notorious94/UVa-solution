#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int>f;
    map<char, int>::iterator it;
    string s;

    int t,max;
    scanf("%d\n", &t);
    for(int i=1;i<=t;i++)
    {
        getline(cin, s);
        for(int a=0;s[a]!='\0';a++)
        {
            if(isalpha(s[a]))
            {
                s[a]=tolower(s[a]);
                f[s[a]]++;
            }
            if(a==0)
            {
                max=f[s[a]];
                continue;
            }
            if(max<f[s[a]])
                max=f[s[a]];
        }

        for(it=f.begin();it!=f.end();it++)
            if(it->second==max)
                printf("%c",it->first);
        printf("\n");
        f.clear();
    }
    return 0;
}
