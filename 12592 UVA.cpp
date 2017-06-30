#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t,size;

    scanf("%d\n", &t);

    t*=2;

    string s[t],choice;
    size=t;

    for(int i=0;i<t;i++)
        getline(cin,s[i]);

    scanf("%d\n", &t);

    while(t--)
    {
        getline(cin,choice);

        for(int i=0;i<size;i+=2)
            if(choice==s[i])
            {
                cout<<s[i+1]<<endl;
                break;
            }
    }

    return 0;
}
