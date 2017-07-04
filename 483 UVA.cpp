
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char s[100000];
    string word;
    while(gets(s))
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]==32)
            {
                reverse(word.begin(),word.end());
                cout<<word<<" ";
                word.clear();
            }
            else
                word.push_back(s[i]);
        }
        reverse(word.begin(),word.end());
        cout<<word<<"\n";
        word.clear();
    }
    return 0;
}
