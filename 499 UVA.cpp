#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int>f;
    map<char, int>::iterator it;
    string s;
    int max;
    while(getline(cin,s))
    {
        sort(s.begin(),s.end());

        for(int i=0;s[i]!='\0';i++)
        {
            if(isalpha(s[i]))
                f[s[i]]++;
            if(i==0)
            {
                max=f[s[i]];
                continue;
            }
            if(max<f[s[i]])
                max=f[s[i]];
        }

        for(it=f.begin();it!=f.end();it++)
            if(it->second==max)
                printf("%c",it->first);
        printf(" %d\n", max);
        f.clear();
    }
    return 0;
}
