#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);
    string s[3],m[3],a;

    s[0] = "][poiuytre";
    m[0] = "poiuytrewq";
    s[1] = "\\';lkjhgfd";
    m[1] = ";lkjhgfdsa";
    s[2] = "/.,mnbvc";
    m[2] = ",mnbvcxz";

    map<char,char>route;

    for(int i=0;i<3;i++)
        for(int j=0;j<s[i].size();j++)
            route[s[i][j]] = m[i][j];

    while(getline(cin,a))
    {
        for(int i=0;a[i];i++)
        {
            if(ispunct(a[i]))
                printf("%c",route[a[i]]);
            else if(a[i]==32)
                printf("%c",a[i]);
            else if(isalpha(a[i]))
            {
                a[i]=tolower(a[i]);
                printf("%c",route[a[i]]);
            }
        }
        cout<<endl;
    }
    return 0;
}
